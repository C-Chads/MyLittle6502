/* Fake6502 CPU emulator core v1.3 *******************
 *Original Author:Mike Chambers (miker00lz@gmail.com)*
 *                                                   *
 *New Author:David MHS Webster (github.com/gek169)   *
 *    Leave a star on github to show thanks for this *
 *        FULLY PUBLIC DOMAIN, CC0 CODE              *
 * Which I give to you and the world with absolutely *
 *  no attribution, monetary compensation, or        *
 *  copyleft requirement. Just write code!           *
 *****************************************************
 *       Let all that you do be done with love       *
 *****************************************************
 *This version has been overhauled with major bug    *
 *fixes relating to decimal mode and adc/sbc. I've   *
 *put the emulator through its paces in kernalemu    *
 *as well as run it through an instruction exerciser *
 *to make sure it works properly. I also discovered  *
 *bugs in the instruction exerciser while I was at it*
 *I might contribute some fixes back to them.        *
 *****************************************************
 * v1.3 - refactoring and more bug fixes             *
 * v1.2 - Major bug fixes in handling adc and sbc    *
 * v1.1 - Small bugfix in BIT opcode, but it was the *
 *        difference between a few games in my NES   *
 *        emulator working and being broken!         *
 *        I went through the rest carefully again    *
 *        after fixing it just to make sure I didn't *
 *        have any other typos! (Dec. 17, 2011)      *
 *                                                   *
 * v1.0 - First release (Nov. 24, 2011)              *
 *****************************************************
 * LICENSE: This source code is released into the    *
 * public domain, but if you use it please do give   *
 * credit. I put a lot of effort into writing this!  *
 * Note by GEK: this is not a requirement.           *
 *****************************************************
 * Fake6502 is a MOS Technology 6502 CPU emulation   *
 * engine in C. It was written as part of a Nintendo *
 * Entertainment System emulator I've been writing.  *
 *                                                   *
 * A couple important things to know about are two   *
 * defines in the code. One is "UNDOCUMENTED" which, *
 * when defined, allows Fake6502 to compile with     *
 * full support for the more predictable             *
 * undocumented instructions of the 6502. If it is   *
 * undefined, undocumented opcodes just act as NOPs. *
 *                                                   *
 * The other define is "NES_CPU", which causes the   *
 * code to compile without support for binary-coded  *
 * decimal (BCD) support for the ADC and SBC         *
 * opcodes. The Ricoh 2A03 CPU in the NES does not   *
 * support BCD, but is otherwise identical to the    *
 * standard MOS 6502. (Note that this define is      *
 * enabled in this file if you haven't changed it    *
 * yourself. If you're not emulating a NES, you      *
 * should comment it out.)                           *
 *                                                   *
 * If you do discover an error in timing accuracy,   *
 * or operation in general please e-mail me at the   *
 * address above so that I can fix it. Thank you!    *
 *                                                   *
 *****************************************************
 * Usage:                                            *
 *                                                   *
 * Fake6502 requires you to provide two external     *
 * functions:                                        *
 *                                                   *
 * uint8 read6502(ushort address)                    *
 * void write6502(ushort address, uint8 value)       *
 *                                                   *
 * You may optionally pass Fake6502 the pointer to a *
 * function which you want to be called after every  *
 * emulated instruction. This function should be a   *
 * void with no parameters expected to be passed to  *
 * it.                                               *
 *                                                   *
 * This can be very useful. For example, in a NES    *
 * emulator, you check the number of clock ticks     *
 * that have passed so you can know when to handle   *
 * APU events.                                       *
 *                                                   *
 * To pass Fake6502 this pointer, use the            *
 * hookexternal(void *funcptr) function provided.    *
 *                                                   *
 * To disable the hook later, pass NULL to it.       *
 *****************************************************
 * Useful functions in this emulator:                *
 *                                                   *
 * void reset6502()                                  *
 *   - Call this once before you begin execution.    *
 *                                                   *
 * uint32 exec6502(uint32 tickcount)                 *
 *   - Execute 6502 code up to the next specified    *
 *     count of clock ticks.                         *
 *                                                   *
 * uint32 step6502()                                   *
 *   - Execute a single instrution.                  *
 *                                                   *
 * void irq6502()                                    *
 *   - Trigger a hardware IRQ in the 6502 core.      *
 *                                                   *
 * void nmi6502()                                    *
 *   - Trigger an NMI in the 6502 core.              *
 *                                                   *
 * void hookexternal(void *funcptr)                  *
 *   - Pass a pointer to a void function taking no   *
 *     parameters. This will cause Fake6502 to call  *
 *     that function once after each emulated        *
 *     instruction.                                  *
 *                                                   *
 *****************************************************
 * Useful variables in this emulator:                *
 *                                                   *
 * uint32 clockticks6502                             *
 *   - A running total of the emulated cycle count   *
 *     during a call to exec6502.                    *
 * uint32 instructions                               *
 *   - A running total of the total emulated         *
 *     instruction count. This is not related to     *
 *     clock cycle timing.                           *
 *                                                   *
 *****************************************************/


/*
	6510 EMULATION NOTES:
	1) On the 6510 processor, the only difference is that the addresses 0 and 1 are used
	for data direction and data, respectively.

	2) The initial value of address 0 should always be 0.

	3) Read this page
	https://ist.uwaterloo.ca/~schepers/MJK/6510.html
*/

#include <stdio.h>
#ifdef FAKE6502_USE_STDINT
#include <stdint.h>
typedef uint16_t ushort;
typedef unsigned char uint8;
typedef uint32_t uint32
#else
typedef unsigned short ushort ;
typedef unsigned char uint8;

#ifdef FAKE6502_USE_LONG
typedef unsigned long uint32;
#else
typedef unsigned int uint32;
#endif

#endif
/*
	when this is defined, undocumented opcodes are handled.
	otherwise, they're simply treated as NOPs.
*/
#define UNDOCUMENTED

/*
* #define NES_CPU
* when this is defined, the binary-coded decimal (BCD)
* status flag is not honored by ADC and SBC. the 2A03
* CPU in the Nintendo Entertainment System does not
* support BCD operation.
*/


#define FLAG_CARRY     0x01
#define FLAG_ZERO      0x02
#define FLAG_INTERRUPT 0x04
#define FLAG_DECIMAL   0x08
/*bits 4 and 5.*/
#define FLAG_BREAK     0x10
#define FLAG_CONSTANT  0x20
#define FLAG_OVERFLOW  0x40
#define FLAG_SIGN      0x80

#define BASE_STACK     0x100

#define saveaccum(n) a = (uint8)((n) & 0x00FF)


/*flag modifier macros*/
#define setcarry() status |= FLAG_CARRY
#define clearcarry() status &= (~FLAG_CARRY)
#define setzero() status |= FLAG_ZERO
#define clearzero() status &= (~FLAG_ZERO)
#define setinterrupt() status |= FLAG_INTERRUPT
#define clearinterrupt() status &= (~FLAG_INTERRUPT)
#define setdecimal() status |= FLAG_DECIMAL
#define cleardecimal() status &= (~FLAG_DECIMAL)
#define setoverflow() status |= FLAG_OVERFLOW
#define clearoverflow() status &= (~FLAG_OVERFLOW)
#define setsign() status |= FLAG_SIGN
#define clearsign() status &= (~FLAG_SIGN)


/*flag calculation macros*/
#define zerocalc(n) {\
    if ((n) & 0x00FF) clearzero();\
        else setzero();\
}

#define signcalc(n) {\
    if ((n) & 0x0080) setsign();\
        else clearsign();\
}

#define carrycalc(n) {\
    if ((n) & 0xFF00) setcarry();\
        else clearcarry();\
}

#define overflowcalc(n, m, o) { /* n = result, m = accumulator, o = memory */ \
    if (((n) ^ (ushort)(m)) & ((n) ^ (o)) & 0x0080) setoverflow();\
        else clearoverflow();\
}


#ifdef FAKE6502_NOT_STATIC
/*6502 CPU registers*/
ushort pc;
uint8 sp, a, x, y, status;
/*helper variables*/
uint32 instructions = 0; 
uint32 clockticks6502 = 0;
uint32 clockgoal6502 = 0;
ushort oldpc, ea, reladdr, value, result;
uint8 opcode, oldstatus;
void reset6502();
void nmi6502();
void irq6502();
void irq6502();
uint32 exec6502(uint32 tickcount);
uint32 step6502();
void hookexternal(void *funcptr);
#else
static ushort pc;
static uint8 sp, a, x, y, status;
static uint32 instructions = 0; 
static uint32 clockticks6502 = 0;
static uint32 clockgoal6502 = 0; 
static ushort oldpc, ea, reladdr, value, result;
static uint8 opcode, oldstatus;
#endif
/*externally supplied functions*/
extern uint8 read6502(ushort address);
extern void write6502(ushort address, uint8 value);


#ifndef FAKE6502_INCLUDE
/*a few general functions used by various other functions*/
static void push_6502_16(ushort pushval) {
    write6502(BASE_STACK + sp, (pushval >> 8) & 0xFF);
    write6502(BASE_STACK + ((sp - 1) & 0xFF), pushval & 0xFF);
    sp -= 2;
}

static void push_6502_8(uint8 pushval) {
    write6502(BASE_STACK + sp--, pushval);
}

static ushort pull_6502_16() {
    ushort temp16;
    temp16 = read6502(BASE_STACK + ((sp + 1) & 0xFF)) | ((ushort)read6502(BASE_STACK + ((sp + 2) & 0xFF)) << 8);
    sp += 2;
    return(temp16);
}

static uint8 pull_6502_8() {
    return (read6502(BASE_STACK + ++sp));
}

static ushort mem_6502_read16(ushort addr) {
    return ((ushort)read6502(addr) |
            ((ushort)read6502(addr + 1) << 8));
}

void reset6502() {
	/*
	    pc = (ushort)read6502(0xFFFC) | ((ushort)read6502(0xFFFD) << 8);
	    a = 0;
	    x = 0;
	    y = 0;
	    sp = 0xFD;
	    status |= FLAG_CONSTANT;
    */
    read6502(0x00ff);
    read6502(0x00ff);
    read6502(0x00ff);
    read6502(0x0100);
    read6502(0x01ff);
    read6502(0x01fe);
    pc = mem_6502_read16(0xfffc);
    sp = 0xfd;
    status |= FLAG_CONSTANT | FLAG_INTERRUPT;
}


static void (*addrtable[256])();
static void (*optable[256])();
static uint8 penaltyop, penaltyaddr;

/*addressing mode functions, calculates effective addresses*/
static void imp() { 
}

/*addressing mode functions, calculates effective addresses*/
static void acc() { 
}

/*addressing mode functions, calculates effective addresses*/
static void imm() { 
    ea = pc++;
}

static void zp() { /*zero-page*/
    ea = (ushort)read6502((ushort)pc++);
}

static void zpx() { /*zero-page,X*/
    ea = ((ushort)read6502((ushort)pc++) + (ushort)x) & 0xFF; /*zero-page wraparound*/
}

static void zpy() { /*zero-page,Y*/
    ea = ((ushort)read6502((ushort)pc++) + (ushort)y) & 0xFF; /*zero-page wraparound*/
}

static void rel() { /*relative for branch ops (8-bit immediate value, sign-extended)*/
    reladdr = (ushort)read6502(pc++);
    if (reladdr & 0x80) reladdr |= 0xFF00;
}

static void abso() { /*absolute*/
    ea = (ushort)read6502(pc) | ((ushort)read6502(pc+1) << 8);
    pc += 2;
}

static void absx() { /*absolute,X*/
    ushort startpage;
    ea = ((ushort)read6502(pc) | ((ushort)read6502(pc+1) << 8));
    startpage = ea & 0xFF00;
    ea += (ushort)x;

    if (startpage != (ea & 0xFF00)) { /*one cycle penlty for page-crossing on some opcodes*/
        penaltyaddr = 1;
    }

    pc += 2;
}

static void absy() { /*absolute,Y*/
    ushort startpage;
    ea = ((ushort)read6502(pc) | ((ushort)read6502(pc+1) << 8));
    startpage = ea & 0xFF00;
    ea += (ushort)y;

    if (startpage != (ea & 0xFF00)) { /*one cycle penlty for page-crossing on some opcodes*/
        penaltyaddr = 1;
    }

    pc += 2;
}

static void ind() { /*indirect*/
    ushort eahelp, eahelp2;
    eahelp = (ushort)read6502(pc) | (ushort)((ushort)read6502(pc+1) << 8);
    eahelp2 = (eahelp & 0xFF00) | ((eahelp + 1) & 0x00FF); /*replicate 6502 page-boundary wraparound bug*/
    ea = (ushort)read6502(eahelp) | ((ushort)read6502(eahelp2) << 8);
    pc += 2;
}

static void indx() { /* (indirect,X)*/
    ushort eahelp;
    eahelp = (ushort)(((ushort)read6502(pc++) + (ushort)x) & 0xFF); /*zero-page wraparound for table pointer*/
    ea = (ushort)read6502(eahelp & 0x00FF) | ((ushort)read6502((eahelp+1) & 0x00FF) << 8);
}

static void indy() { /* (indirect),Y*/
    ushort eahelp, eahelp2, startpage;
    eahelp = (ushort)read6502(pc++);
    eahelp2 = (eahelp & 0xFF00) | ((eahelp + 1) & 0x00FF); /*zero-page wraparound*/
    ea = (ushort)read6502(eahelp) | ((ushort)read6502(eahelp2) << 8);
    startpage = ea & 0xFF00;
    ea += (ushort)y;

    if (startpage != (ea & 0xFF00)) { /*one cycle penlty for page-crossing on some opcodes*/
        penaltyaddr = 1;
    }
}

static ushort getvalue() {
    if (addrtable[opcode] == acc) return((ushort)a);
        else return((ushort)read6502(ea));
}

static ushort getvalue16() {
    return((ushort)read6502(ea) | ((ushort)read6502(ea+1) << 8));
}

static void putvalue(ushort saveval) {
    if (addrtable[opcode] == acc) a = (uint8)(saveval & 0x00FF);
        else write6502(ea, (saveval & 0x00FF));
}


/*instruction handler functions*/
static void adc() {
    penaltyop = 1;
#ifndef NES_CPU
    if (status & FLAG_DECIMAL) {
        ushort AL, A, result_dec;
        A = a;
        value = getvalue();
        result_dec = (ushort)A + value + (ushort)(status & FLAG_CARRY); /*dec*/
        
        AL = (A & 0x0F) + (value & 0x0F) + (ushort)(status & FLAG_CARRY);  /*SEQ 1A OR 2A*/
        if(AL >= 0xA) AL = ((AL + 0x06) & 0x0F) + 0x10; /*SEQ 1B OR SEQ 2B*/
        A = (A & 0xF0) + (value & 0xF0) + AL; /*SEQ2C OR SEQ 1C*/
        if(A & 0x80) setsign(); else clearsign(); /*SEQ 2E it says "bit 7"*/
        if(A >= 0xA0) A += 0x60; /*SEQ 1E*/
        result = A; /*1F*/
        if(A & 0xff80) setoverflow();else clearoverflow();
        if(A >= 0x100) setcarry(); else clearcarry(); /*SEQ 1G*/
		
        zerocalc(result_dec); /*Original nmos does zerocalc on the binary result.*/
    } else 
#endif
    {
        value = getvalue();
        result = (ushort)a + value + (ushort)(status & FLAG_CARRY);
        carrycalc(result);
        zerocalc(result);
        overflowcalc(result, a, value);
        signcalc(result);
    }
    saveaccum(result);
}

static void and() {
    penaltyop = 1;
    value = getvalue();
    result = (ushort)a & value;
   
    zerocalc(result);
    signcalc(result);
   
    saveaccum(result);
}

static void asl() {
    value = getvalue();
    result = value << 1;

    carrycalc(result);
    zerocalc(result);
    signcalc(result);
   
    putvalue(result);
}

static void bcc() {
    if ((status & FLAG_CARRY) == 0) {
        oldpc = pc;
        pc += reladdr;
        if ((oldpc & 0xFF00) != (pc & 0xFF00)) clockticks6502 += 2; /*check if jump crossed a page boundary*/
            else clockticks6502++;
    }
}

static void bcs() {
    if ((status & FLAG_CARRY) == FLAG_CARRY) {
        oldpc = pc;
        pc += reladdr;
        if ((oldpc & 0xFF00) != (pc & 0xFF00)) clockticks6502 += 2; /*check if jump crossed a page boundary*/
            else clockticks6502++;
    }
}

static void beq() {
    if ((status & FLAG_ZERO) == FLAG_ZERO) {
        oldpc = pc;
        pc += reladdr;
        if ((oldpc & 0xFF00) != (pc & 0xFF00)) clockticks6502 += 2; /*check if jump crossed a page boundary*/
            else clockticks6502++;
    }
}

static void bit() {
    value = getvalue();
    result = (ushort)a & value;
   
    zerocalc(result);
    status = (status & 0x3F) | (uint8)(value & 0xC0);
}

static void bmi() {
    if ((status & FLAG_SIGN) == FLAG_SIGN) {
        oldpc = pc;
        pc += reladdr;
        if ((oldpc & 0xFF00) != (pc & 0xFF00)) clockticks6502 += 2; /*check if jump crossed a page boundary*/
            else clockticks6502++;
    }
}

static void bne() {
    if ((status & FLAG_ZERO) == 0) {
        oldpc = pc;
        pc += reladdr;
        if ((oldpc & 0xFF00) != (pc & 0xFF00)) clockticks6502 += 2; /*check if jump crossed a page boundary*/
            else clockticks6502++;
    }
}

static void bpl() {
    if ((status & FLAG_SIGN) == 0) {
        oldpc = pc;
        pc += reladdr;
        if ((oldpc & 0xFF00) != (pc & 0xFF00)) clockticks6502 += 2; /*check if jump crossed a page boundary*/
            else clockticks6502++;
    }
}

static void brk_6502() {
    pc++;
    push_6502_16(pc); 
    push_6502_8(status | FLAG_BREAK); 
    setinterrupt();
    pc = (ushort)read6502(0xFFFE) | ((ushort)read6502(0xFFFF) << 8);
}

static void bvc() {
    if ((status & FLAG_OVERFLOW) == 0) {
        oldpc = pc;
        pc += reladdr;
        if ((oldpc & 0xFF00) != (pc & 0xFF00)) clockticks6502 += 2; /*check if jump crossed a page boundary*/
            else clockticks6502++;
    }
}

static void bvs() {
    if ((status & FLAG_OVERFLOW) == FLAG_OVERFLOW) {
        oldpc = pc;
        pc += reladdr;
        if ((oldpc & 0xFF00) != (pc & 0xFF00)) clockticks6502 += 2; /*check if jump crossed a page boundary*/
            else clockticks6502++;
    }
}

static void clc() {
    clearcarry();
}

static void cld() {
    cleardecimal();
}

static void cli() {
    clearinterrupt();
}

static void clv() {
    clearoverflow();
}

static void cmp() {
    penaltyop = 1;
    value = getvalue();
    result = (ushort)a - value;
   
    if (a >= (uint8)(value & 0x00FF)) setcarry();
        else clearcarry();
    if (a == (uint8)(value & 0x00FF)) setzero();
        else clearzero();
    signcalc(result);
}

static void cpx() {
    value = getvalue();
    result = (ushort)x - value;
   
    if (x >= (uint8)(value & 0x00FF)) setcarry();
        else clearcarry();
    if (x == (uint8)(value & 0x00FF)) setzero();
        else clearzero();
    signcalc(result);
}

static void cpy() {
    value = getvalue();
    result = (ushort)y - value;
   
    if (y >= (uint8)(value & 0x00FF)) setcarry();
        else clearcarry();
    if (y == (uint8)(value & 0x00FF)) setzero();
        else clearzero();
    signcalc(result);
}

static void dec() {
    value = getvalue();
    result = value - 1;
   
    zerocalc(result);
    signcalc(result);
   
    putvalue(result);
}

static void dex() {
    x--;
   
    zerocalc(x);
    signcalc(x);
}

static void dey() {
    y--;
   
    zerocalc(y);
    signcalc(y);
}

static void eor() {
    penaltyop = 1;
    value = getvalue();
    result = (ushort)a ^ value;
   
    zerocalc(result);
    signcalc(result);
   
    saveaccum(result);
}

static void inc() {
    value = getvalue();
    result = value + 1;
   
    zerocalc(result);
    signcalc(result);
   
    putvalue(result);
}

static void inx() {
    x++;
   
    zerocalc(x);
    signcalc(x);
}

static void iny() {
    y++;
   
    zerocalc(y);
    signcalc(y);
}

static void jmp() {
    pc = ea;
}

static void jsr() {
    push_6502_16(pc - 1);
    pc = ea;
}

static void lda() {
    penaltyop = 1;
    value = getvalue();
    a = (uint8)(value & 0x00FF);
   
    zerocalc(a);
    signcalc(a);
}

static void ldx() {
    penaltyop = 1;
    value = getvalue();
    x = (uint8)(value & 0x00FF);
   
    zerocalc(x);
    signcalc(x);
}

static void ldy() {
    penaltyop = 1;
    value = getvalue();
    y = (uint8)(value & 0x00FF);
   
    zerocalc(y);
    signcalc(y);
}

static void lsr() {
    value = getvalue();
    result = value >> 1;
   
    if (value & 1) setcarry();
        else clearcarry();
    zerocalc(result);
    signcalc(result);
   
    putvalue(result);
}

static void nop() {
    switch (opcode) {
        case 0x1C:
        case 0x3C:
        case 0x5C:
        case 0x7C:
        case 0xDC:
        case 0xFC:
            penaltyop = 1;
            break;
    }
}

static void ora() {
    penaltyop = 1;
    value = getvalue();
    result = (ushort)a | value;
   
    zerocalc(result);
    signcalc(result);
   
    saveaccum(result);
}

static void pha() {
    push_6502_8(a);
}

static void php() {
    push_6502_8(status | FLAG_BREAK);
}

static void pla() {
    a = pull_6502_8();
   
    zerocalc(a);
    signcalc(a);
}

static void plp() {
    status = pull_6502_8() | FLAG_CONSTANT;
}

static void rol() {
    value = getvalue();
    result = (value << 1) | (status & FLAG_CARRY);
   
    carrycalc(result);
    zerocalc(result);
    signcalc(result);
   
    putvalue(result);
}

static void ror() {
    value = getvalue();
    result = (value >> 1) | ((status & FLAG_CARRY) << 7);
   
    if (value & 1) setcarry();
        else clearcarry();
    zerocalc(result);
    signcalc(result);
   
    putvalue(result);
}

static void rti() {
    status = pull_6502_8();
    value = pull_6502_16();
    pc = value;
}

static void rts() {
    value = pull_6502_16();
    pc = value + 1;
}

static void sbc() {
    penaltyop = 1;
#ifndef NES_CPU
    if (status & FLAG_DECIMAL) {
    	ushort result_dec, A, AL, B, C;
    	A = a;
    	C = (ushort)(status & FLAG_CARRY);
     	value = getvalue();B = value;value = value ^ 0x00FF;
    	result_dec = (ushort)a + value + (ushort)(status & FLAG_CARRY); /*dec*/
		/*Both Cmos and Nmos*/
    	carrycalc(result_dec); 
    	overflowcalc(result_dec, a, value); 
    	/*NMOS ONLY*/
    	signcalc(result_dec);
    	zerocalc(result_dec);
		/*Sequence 3 is NMOS ONLY*/
    	AL = (A & 0x0F) - (B & 0x0F) + C -1; /* 3a*/
    	if(AL & 0x8000)  AL =  ((AL - 0x06) & 0x0F) - 0x10; /*3b*/
    	A = (A & 0xF0) - (B & 0xF0) + AL; /*3c*/
    	if(A & 0x8000) A = A - 0x60; /*3d*/
    	result = A; /*3e*/
    } else 
#endif
    {
        value = getvalue() ^ 0x00FF;
        result = (ushort)a + value + (ushort)(status & FLAG_CARRY);
	
        carrycalc(result);
        zerocalc(result);
        overflowcalc(result, a, value);
        signcalc(result);
    }
    saveaccum(result);
}

static void sec() {
    setcarry();
}

static void sed() {
    setdecimal();
}

static void sei() {
    setinterrupt();
}

static void sta() {
    putvalue(a);
}

static void stx() {
    putvalue(x);
}

static void sty() {
    putvalue(y);
}

static void tax() {
    x = a;
   
    zerocalc(x);
    signcalc(x);
}

static void tay() {
    y = a;
   
    zerocalc(y);
    signcalc(y);
}

static void tsx() {
    x = sp;
   
    zerocalc(x);
    signcalc(x);
}

static void txa() {
    a = x;
   
    zerocalc(a);
    signcalc(a);
}

static void txs() {
    sp = x;
}

static void tya() {
    a = y;
   
    zerocalc(a);
    signcalc(a);
}

/*undocumented instructions~~~~~~~~~~~~~~~~~~~~~~~~~*/
#ifdef UNDOCUMENTED
    static void lax() {
        lda();
        ldx();
    }

    static void sax() {
        sta();
        stx();
        putvalue(a & x);
        if (penaltyop && penaltyaddr) clockticks6502--;
    }

    static void dcp() {
        dec();
        cmp();
        if (penaltyop && penaltyaddr) clockticks6502--;
    }

    static void isb() {
        inc();
        sbc();
        if (penaltyop && penaltyaddr) clockticks6502--;
    }

    static void slo() {
        asl();
        ora();
        if (penaltyop && penaltyaddr) clockticks6502--;
    }

    static void rla() {
        rol();
        and();
        if (penaltyop && penaltyaddr) clockticks6502--;
    }

    static void sre() {
        lsr();
        eor();
        if (penaltyop && penaltyaddr) clockticks6502--;
    }

    static void rra() {
        ror();
        adc();
        if (penaltyop && penaltyaddr) clockticks6502--;
    }
#else
    #define lax nop
    #define sax nop
    #define dcp nop
    #define isb nop
    #define slo nop
    #define rla nop
    #define sre nop
    #define rra nop
#endif


static void (*addrtable[256])() = {
/*        |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  A  |  B  |  C  |  D  |  E  |  F  |     */
/* 0 */     imp, indx,  imp, indx,   zp,   zp,   zp,   zp,  imp,  imm,  acc,  imm, abso, abso, abso, abso, /* 0 */
/* 1 */     rel, indy,  imp, indy,  zpx,  zpx,  zpx,  zpx,  imp, absy,  imp, absy, absx, absx, absx, absx, /* 1 */
/* 2 */    abso, indx,  imp, indx,   zp,   zp,   zp,   zp,  imp,  imm,  acc,  imm, abso, abso, abso, abso, /* 2 */
/* 3 */     rel, indy,  imp, indy,  zpx,  zpx,  zpx,  zpx,  imp, absy,  imp, absy, absx, absx, absx, absx, /* 3 */
/* 4 */     imp, indx,  imp, indx,   zp,   zp,   zp,   zp,  imp,  imm,  acc,  imm, abso, abso, abso, abso, /* 4 */
/* 5 */     rel, indy,  imp, indy,  zpx,  zpx,  zpx,  zpx,  imp, absy,  imp, absy, absx, absx, absx, absx, /* 5 */
/* 6 */     imp, indx,  imp, indx,   zp,   zp,   zp,   zp,  imp,  imm,  acc,  imm,  ind, abso, abso, abso, /* 6 */
/* 7 */     rel, indy,  imp, indy,  zpx,  zpx,  zpx,  zpx,  imp, absy,  imp, absy, absx, absx, absx, absx, /* 7 */
/* 8 */     imm, indx,  imm, indx,   zp,   zp,   zp,   zp,  imp,  imm,  imp,  imm, abso, abso, abso, abso, /* 8 */
/* 9 */     rel, indy,  imp, indy,  zpx,  zpx,  zpy,  zpy,  imp, absy,  imp, absy, absx, absx, absy, absy, /* 9 */
/* A */     imm, indx,  imm, indx,   zp,   zp,   zp,   zp,  imp,  imm,  imp,  imm, abso, abso, abso, abso, /* A */
/* B */     rel, indy,  imp, indy,  zpx,  zpx,  zpy,  zpy,  imp, absy,  imp, absy, absx, absx, absy, absy, /* B */
/* C */     imm, indx,  imm, indx,   zp,   zp,   zp,   zp,  imp,  imm,  imp,  imm, abso, abso, abso, abso, /* C */
/* D */     rel, indy,  imp, indy,  zpx,  zpx,  zpx,  zpx,  imp, absy,  imp, absy, absx, absx, absx, absx, /* D */
/* E */     imm, indx,  imm, indx,   zp,   zp,   zp,   zp,  imp,  imm,  imp,  imm, abso, abso, abso, abso, /* E */
/* F */     rel, indy,  imp, indy,  zpx,  zpx,  zpx,  zpx,  imp, absy,  imp, absy, absx, absx, absx, absx  /* F */
};

static void (*optable[256])() = {
/*        |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  A  |  B  |  C  |  D  |  E  |  F  |      */
/* 0 */      brk_6502,  ora,  nop,  slo,  nop,  ora,  asl,  slo,  php,  ora,  asl,  nop,  nop,  ora,  asl,  slo, /* 0 */
/* 1 */      bpl,  ora,  nop,  slo,  nop,  ora,  asl,  slo,  clc,  ora,  nop,  slo,  nop,  ora,  asl,  slo, /* 1 */
/* 2 */      jsr,  and,  nop,  rla,  bit,  and,  rol,  rla,  plp,  and,  rol,  nop,  bit,  and,  rol,  rla, /* 2 */
/* 3 */      bmi,  and,  nop,  rla,  nop,  and,  rol,  rla,  sec,  and,  nop,  rla,  nop,  and,  rol,  rla, /* 3 */
/* 4 */      rti,  eor,  nop,  sre,  nop,  eor,  lsr,  sre,  pha,  eor,  lsr,  nop,  jmp,  eor,  lsr,  sre, /* 4 */
/* 5 */      bvc,  eor,  nop,  sre,  nop,  eor,  lsr,  sre,  cli,  eor,  nop,  sre,  nop,  eor,  lsr,  sre, /* 5 */
/* 6 */      rts,  adc,  nop,  rra,  nop,  adc,  ror,  rra,  pla,  adc,  ror,  nop,  jmp,  adc,  ror,  rra, /* 6 */
/* 7 */      bvs,  adc,  nop,  rra,  nop,  adc,  ror,  rra,  sei,  adc,  nop,  rra,  nop,  adc,  ror,  rra, /* 7 */
/* 8 */      nop,  sta,  nop,  sax,  sty,  sta,  stx,  sax,  dey,  nop,  txa,  nop,  sty,  sta,  stx,  sax, /* 8 */
/* 9 */      bcc,  sta,  nop,  nop,  sty,  sta,  stx,  sax,  tya,  sta,  txs,  nop,  nop,  sta,  nop,  nop, /* 9 */
/* A */      ldy,  lda,  ldx,  lax,  ldy,  lda,  ldx,  lax,  tay,  lda,  tax,  nop,  ldy,  lda,  ldx,  lax, /* A */
/* B */      bcs,  lda,  nop,  lax,  ldy,  lda,  ldx,  lax,  clv,  lda,  tsx,  lax,  ldy,  lda,  ldx,  lax, /* B */
/* C */      cpy,  cmp,  nop,  dcp,  cpy,  cmp,  dec,  dcp,  iny,  cmp,  dex,  nop,  cpy,  cmp,  dec,  dcp, /* C */
/* D */      bne,  cmp,  nop,  dcp,  nop,  cmp,  dec,  dcp,  cld,  cmp,  nop,  dcp,  nop,  cmp,  dec,  dcp, /* D */
/* E */      cpx,  sbc,  nop,  isb,  cpx,  sbc,  inc,  isb,  inx,  sbc,  nop,  sbc,  cpx,  sbc,  inc,  isb, /* E */
/* F */      beq,  sbc,  nop,  isb,  nop,  sbc,  inc,  isb,  sed,  sbc,  nop,  isb,  nop,  sbc,  inc,  isb  /* F */
};

static const uint32 ticktable[256] = {
/*        |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  A  |  B  |  C  |  D  |  E  |  F  |     */
/* 0 */      7,    6,    2,    8,    3,    3,    5,    5,    3,    2,    2,    2,    4,    4,    6,    6,  /* 0 */
/* 1 */      2,    5,    2,    8,    4,    4,    6,    6,    2,    4,    2,    7,    4,    4,    7,    7,  /* 1 */
/* 2 */      6,    6,    2,    8,    3,    3,    5,    5,    4,    2,    2,    2,    4,    4,    6,    6,  /* 2 */
/* 3 */      2,    5,    2,    8,    4,    4,    6,    6,    2,    4,    2,    7,    4,    4,    7,    7,  /* 3 */
/* 4 */      6,    6,    2,    8,    3,    3,    5,    5,    3,    2,    2,    2,    3,    4,    6,    6,  /* 4 */
/* 5 */      2,    5,    2,    8,    4,    4,    6,    6,    2,    4,    2,    7,    4,    4,    7,    7,  /* 5 */
/* 6 */      6,    6,    2,    8,    3,    3,    5,    5,    4,    2,    2,    2,    5,    4,    6,    6,  /* 6 */
/* 7 */      2,    5,    2,    8,    4,    4,    6,    6,    2,    4,    2,    7,    4,    4,    7,    7,  /* 7 */
/* 8 */      2,    6,    2,    6,    3,    3,    3,    3,    2,    2,    2,    2,    4,    4,    4,    4,  /* 8 */
/* 9 */      2,    6,    2,    6,    4,    4,    4,    4,    2,    5,    2,    5,    5,    5,    5,    5,  /* 9 */
/* A */      2,    6,    2,    6,    3,    3,    3,    3,    2,    2,    2,    2,    4,    4,    4,    4,  /* A */
/* B */      2,    5,    2,    5,    4,    4,    4,    4,    2,    4,    2,    4,    4,    4,    4,    4,  /* B */
/* C */      2,    6,    2,    8,    3,    3,    5,    5,    2,    2,    2,    2,    4,    4,    6,    6,  /* C */
/* D */      2,    5,    2,    8,    4,    4,    6,    6,    2,    4,    2,    7,    4,    4,    7,    7,  /* D */
/* E */      2,    6,    2,    8,    3,    3,    5,    5,    2,    2,    2,    2,    4,    4,    6,    6,  /* E */
/* F */      2,    5,    2,    8,    4,    4,    6,    6,    2,    4,    2,    7,    4,    4,    7,    7   /* F */
};


void nmi6502() {
    push_6502_16(pc);
    push_6502_8(status  & ~FLAG_BREAK);
    status |= FLAG_INTERRUPT;
    pc = (ushort)read6502(0xFFFA) | ((ushort)read6502(0xFFFB) << 8);
}

void irq6502() {
	/*
    push_6502_16(pc);
    push_6502_8(status);
    status |= FLAG_INTERRUPT;
    pc = (ushort)read6502(0xFFFE) | ((ushort)read6502(0xFFFF) << 8);
    */
	if ((status & FLAG_INTERRUPT) == 0) {
		push_6502_16(pc);
		push_6502_8(status & ~FLAG_BREAK);
		status |= FLAG_INTERRUPT;
		/*pc = mem_6502_read16(0xfffe);*/
		pc = (ushort)read6502(0xFFFE) | ((ushort)read6502(0xFFFF) << 8);
	}
}

uint8 callexternal = 0;
void (*loopexternal)();

uint32 exec6502(uint32 tickcount) {
	/*
		BUG FIX:
		overflow of unsigned 32 bit integer causes emulation to hang.
		An instruction might cause the tick count to wrap around into the billions.

		The system is changed so that now clockticks 6502 is reset every single time that exec is called.
	*/
    clockgoal6502 = tickcount;
    clockticks6502 = 0;
    while (clockticks6502 < clockgoal6502) {
        opcode = read6502(pc++);
        status |= FLAG_CONSTANT;
        penaltyop = 0;
        penaltyaddr = 0;
       	(*addrtable[opcode])();
        (*optable[opcode])();
        clockticks6502 += ticktable[opcode];
        if (penaltyop && penaltyaddr) {clockticks6502++;}
        instructions++;
        if (callexternal) (*loopexternal)();
    }
	return clockticks6502;
}

uint32 step6502() {
    opcode = read6502(pc++);
    status |= FLAG_CONSTANT;

    penaltyop = 0;
    penaltyaddr = 0;
	clockticks6502 = 0;
    (*addrtable[opcode])();
    (*optable[opcode])();
    clockticks6502 += ticktable[opcode];
    /*The following line goes commented out in Mike Chamber's usage of the 6502 emulator for MOARNES*/
    if (penaltyop && penaltyaddr) clockticks6502++;
    /*clockgoal6502 = clockticks6502; irrelevant.*/ 

    instructions++;

    if (callexternal) (*loopexternal)();
    return clockticks6502;
}

void hookexternal(void *funcptr) {
    if (funcptr != (void *)NULL) {
        loopexternal = funcptr;
        callexternal = 1;
    } else callexternal = 0;
}
/*FAKE6502 INCLUDE*/
#endif

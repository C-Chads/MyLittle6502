/*
		THIS FILE IS NOT IN THE PUBLIC DOMAIN

		The .h file, fake6502.h, however, is.

		SO, don't put this file in your project, or richard stallman's going to be bustin' your ass for source code.

		The author (https://github.com/omarandlorraine/fake6502) 
		wants this file to have copyleft stuff on it.

		So, if you use it, yours does too.

		Sort of like shit. Get a little on your hands? Now it's on everything you touch.
		Here's the shit:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				    GNU GENERAL PUBLIC LICENSE
		       Version 2, June 1991

 Copyright (C) 1989, 1991 Free Software Foundation, Inc.
 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.

			    Preamble

  The licenses for most software are designed to take away your
freedom to share and change it.  By contrast, the GNU General Public
License is intended to guarantee your freedom to share and change free
software--to make sure the software is free for all its users.  This
General Public License applies to most of the Free Software
Foundation's software and to any other program whose authors commit to
using it.  (Some other Free Software Foundation software is covered by
the GNU Library General Public License instead.)  You can apply it to
your programs, too.

  When we speak of free software, we are referring to freedom, not
price.  Our General Public Licenses are designed to make sure that you
have the freedom to distribute copies of free software (and charge for
this service if you wish), that you receive source code or can get it
if you want it, that you can change the software or use pieces of it
in new free programs; and that you know you can do these things.

  To protect your rights, we need to make restrictions that forbid
anyone to deny you these rights or to ask you to surrender the rights.
These restrictions translate to certain responsibilities for you if you
distribute copies of the software, or if you modify it.

  For example, if you distribute copies of such a program, whether
gratis or for a fee, you must give the recipients all the rights that
you have.  You must make sure that they, too, receive or can get the
source code.  And you must show them these terms so they know their
rights.

  We protect your rights with two steps: (1) copyright the software, and
(2) offer you this license which gives you legal permission to copy,
distribute and/or modify the software.

  Also, for each author's protection and ours, we want to make certain
that everyone understands that there is no warranty for this free
software.  If the software is modified by someone else and passed on, we
want its recipients to know that what they have is not the original, so
that any problems introduced by others will not reflect on the original
authors' reputations.

  Finally, any free program is threatened constantly by software
patents.  We wish to avoid the danger that redistributors of a free
program will individually obtain patent licenses, in effect making the
program proprietary.  To prevent this, we have made it clear that any
patent must be licensed for everyone's free use or not licensed at all.

  The precise terms and conditions for copying, distribution and
modification follow.

		    GNU GENERAL PUBLIC LICENSE
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

  0. This License applies to any program or other work which contains
a notice placed by the copyright holder saying it may be distributed
under the terms of this General Public License.  The "Program", below,
refers to any such program or work, and a "work based on the Program"
means either the Program or any derivative work under copyright law:
that is to say, a work containing the Program or a portion of it,
either verbatim or with modifications and/or translated into another
language.  (Hereinafter, translation is included without limitation in
the term "modification".)  Each licensee is addressed as "you".

Activities other than copying, distribution and modification are not
covered by this License; they are outside its scope.  The act of
running the Program is not restricted, and the output from the Program
is covered only if its contents constitute a work based on the
Program (independent of having been made by running the Program).
Whether that is true depends on what the Program does.

  1. You may copy and distribute verbatim copies of the Program's
source code as you receive it, in any medium, provided that you
conspicuously and appropriately publish on each copy an appropriate
copyright notice and disclaimer of warranty; keep intact all the
notices that refer to this License and to the absence of any warranty;
and give any other recipients of the Program a copy of this License
along with the Program.

You may charge a fee for the physical act of transferring a copy, and
you may at your option offer warranty protection in exchange for a fee.

  2. You may modify your copy or copies of the Program or any portion
of it, thus forming a work based on the Program, and copy and
distribute such modifications or work under the terms of Section 1
above, provided that you also meet all of these conditions:

    a) You must cause the modified files to carry prominent notices
    stating that you changed the files and the date of any change.

    b) You must cause any work that you distribute or publish, that in
    whole or in part contains or is derived from the Program or any
    part thereof, to be licensed as a whole at no charge to all third
    parties under the terms of this License.

    c) If the modified program normally reads commands interactively
    when run, you must cause it, when started running for such
    interactive use in the most ordinary way, to print or display an
    announcement including an appropriate copyright notice and a
    notice that there is no warranty (or else, saying that you provide
    a warranty) and that users may redistribute the program under
    these conditions, and telling the user how to view a copy of this
    License.  (Exception: if the Program itself is interactive but
    does not normally print such an announcement, your work based on
    the Program is not required to print an announcement.)

These requirements apply to the modified work as a whole.  If
identifiable sections of that work are not derived from the Program,
and can be reasonably considered independent and separate works in
themselves, then this License, and its terms, do not apply to those
sections when you distribute them as separate works.  But when you
distribute the same sections as part of a whole which is a work based
on the Program, the distribution of the whole must be on the terms of
this License, whose permissions for other licensees extend to the
entire whole, and thus to each and every part regardless of who wrote it.

Thus, it is not the intent of this section to claim rights or contest
your rights to work written entirely by you; rather, the intent is to
exercise the right to control the distribution of derivative or
collective works based on the Program.

In addition, mere aggregation of another work not based on the Program
with the Program (or with a work based on the Program) on a volume of
a storage or distribution medium does not bring the other work under
the scope of this License.

  3. You may copy and distribute the Program (or a work based on it,
under Section 2) in object code or executable form under the terms of
Sections 1 and 2 above provided that you also do one of the following:

    a) Accompany it with the complete corresponding machine-readable
    source code, which must be distributed under the terms of Sections
    1 and 2 above on a medium customarily used for software interchange; or,

    b) Accompany it with a written offer, valid for at least three
    years, to give any third party, for a charge no more than your
    cost of physically performing source distribution, a complete
    machine-readable copy of the corresponding source code, to be
    distributed under the terms of Sections 1 and 2 above on a medium
    customarily used for software interchange; or,

    c) Accompany it with the information you received as to the offer
    to distribute corresponding source code.  (This alternative is
    allowed only for noncommercial distribution and only if you
    received the program in object code or executable form with such
    an offer, in accord with Subsection b above.)

The source code for a work means the preferred form of the work for
making modifications to it.  For an executable work, complete source
code means all the source code for all modules it contains, plus any
associated interface definition files, plus the scripts used to
control compilation and installation of the executable.  However, as a
special exception, the source code distributed need not include
anything that is normally distributed (in either source or binary
form) with the major components (compiler, kernel, and so on) of the
operating system on which the executable runs, unless that component
itself accompanies the executable.

If distribution of executable or object code is made by offering
access to copy from a designated place, then offering equivalent
access to copy the source code from the same place counts as
distribution of the source code, even though third parties are not
compelled to copy the source along with the object code.

  4. You may not copy, modify, sublicense, or distribute the Program
except as expressly provided under this License.  Any attempt
otherwise to copy, modify, sublicense or distribute the Program is
void, and will automatically terminate your rights under this License.
However, parties who have received copies, or rights, from you under
this License will not have their licenses terminated so long as such
parties remain in full compliance.

  5. You are not required to accept this License, since you have not
signed it.  However, nothing else grants you permission to modify or
distribute the Program or its derivative works.  These actions are
prohibited by law if you do not accept this License.  Therefore, by
modifying or distributing the Program (or any work based on the
Program), you indicate your acceptance of this License to do so, and
all its terms and conditions for copying, distributing or modifying
the Program or works based on it.

  6. Each time you redistribute the Program (or any work based on the
Program), the recipient automatically receives a license from the
original licensor to copy, distribute or modify the Program subject to
these terms and conditions.  You may not impose any further
restrictions on the recipients' exercise of the rights granted herein.
You are not responsible for enforcing compliance by third parties to
this License.

  7. If, as a consequence of a court judgment or allegation of patent
infringement or for any other reason (not limited to patent issues),
conditions are imposed on you (whether by court order, agreement or
otherwise) that contradict the conditions of this License, they do not
excuse you from the conditions of this License.  If you cannot
distribute so as to satisfy simultaneously your obligations under this
License and any other pertinent obligations, then as a consequence you
may not distribute the Program at all.  For example, if a patent
license would not permit royalty-free redistribution of the Program by
all those who receive copies directly or indirectly through you, then
the only way you could satisfy both it and this License would be to
refrain entirely from distribution of the Program.

If any portion of this section is held invalid or unenforceable under
any particular circumstance, the balance of the section is intended to
apply and the section as a whole is intended to apply in other
circumstances.

It is not the purpose of this section to induce you to infringe any
patents or other property right claims or to contest validity of any
such claims; this section has the sole purpose of protecting the
integrity of the free software distribution system, which is
implemented by public license practices.  Many people have made
generous contributions to the wide range of software distributed
through that system in reliance on consistent application of that
system; it is up to the author/donor to decide if he or she is willing
to distribute software through any other system and a licensee cannot
impose that choice.

This section is intended to make thoroughly clear what is believed to
be a consequence of the rest of this License.

  8. If the distribution and/or use of the Program is restricted in
certain countries either by patents or by copyrighted interfaces, the
original copyright holder who places the Program under this License
may add an explicit geographical distribution limitation excluding
those countries, so that distribution is permitted only in or among
countries not thus excluded.  In such case, this License incorporates
the limitation as if written in the body of this License.

  9. The Free Software Foundation may publish revised and/or new versions
of the General Public License from time to time.  Such new versions will
be similar in spirit to the present version, but may differ in detail to
address new problems or concerns.

Each version is given a distinguishing version number.  If the Program
specifies a version number of this License which applies to it and "any
later version", you have the option of following the terms and conditions
either of that version or of any later version published by the Free
Software Foundation.  If the Program does not specify a version number of
this License, you may choose any version ever published by the Free Software
Foundation.

  10. If you wish to incorporate parts of the Program into other free
programs whose distribution conditions are different, write to the author
to ask for permission.  For software which is copyrighted by the Free
Software Foundation, write to the Free Software Foundation; we sometimes
make exceptions for this.  Our decision will be guided by the two goals
of preserving the free status of all derivatives of our free software and
of promoting the sharing and reuse of software generally.

			    NO WARRANTY

  11. BECAUSE THE PROGRAM IS LICENSED FREE OF CHARGE, THERE IS NO WARRANTY
FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW.  EXCEPT WHEN
OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES
PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED
OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE ENTIRE RISK AS
TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU.  SHOULD THE
PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING,
REPAIR OR CORRECTION.

  12. IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING
WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MAY MODIFY AND/OR
REDISTRIBUTE THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES,
INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING
OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED
TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY
YOU OR THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER
PROGRAMS), EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE
POSSIBILITY OF SUCH DAMAGES.

		     END OF TERMS AND CONDITIONS

	Appendix: How to Apply These Terms to Your New Programs

  If you develop a new program, and you want it to be of the greatest
possible use to the public, the best way to achieve this is to make it
free software which everyone can redistribute and change under these terms.

  To do so, attach the following notices to the program.  It is safest
to attach them to the start of each source file to most effectively
convey the exclusion of warranty; and each file should have at least
the "copyright" line and a pointer to where the full notice is found.

    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 19yy  <name of author>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA

Also add information on how to contact you by electronic and paper mail.

If the program is interactive, make it output a short notice like this
when it starts in an interactive mode:

    Gnomovision version 69, Copyright (C) 19yy name of author
    Gnomovision comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
    This is free software, and you are welcome to redistribute it
    under certain conditions; type `show c' for details.

The hypothetical commands `show w' and `show c' should show the appropriate
parts of the General Public License.  Of course, the commands you use may
be called something other than `show w' and `show c'; they could even be
mouse-clicks or menu items--whatever suits your program.

You should also get your employer (if you work as a programmer) or your
school, if any, to sign a "copyright disclaimer" for the program, if
necessary.  Here is a sample; alter the names:

  Yoyodyne, Inc., hereby disclaims all copyright interest in the program
  `Gnomovision' (which makes passes at compilers) written by James Hacker.

  <signature of Ty Coon>, 1 April 1989
  Ty Coon, President of Vice

This General Public License does not permit incorporating your program into
proprietary programs.  If your program is a subroutine library, you may
consider it more useful to permit linking proprietary applications with the
library.  If this is what you want to do, use the GNU Library General
Public License instead of this License.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Yuck! Back to code.

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fake65c02.h"

#define FLAG_CARRY 0x01
#define FLAG_ZERO 0x02
#define FLAG_INTERRUPT 0x04
#define FLAG_DECIMAL 0x08
#define FLAG_BREAK 0x10
#define FLAG_CONSTANT 0x20
#define FLAG_OVERFLOW 0x40
#define FLAG_SIGN 0x80

#define CHECK(var, shouldbe)                                                   \
    if (var != shouldbe)                                                   \
        return printf("line %d: " #var " should've been %04x but was %04x\n",  \
                      __LINE__, shouldbe, var);
#define CHECKMEM(var, shouldbe)                                                \
    if (read6502(var) != (shouldbe))                                     \
        return printf("line %d: memory location " #var                         \
                      " should've been %02x but was %02x\n",                   \
                      __LINE__, shouldbe, read6502(var));

#define CHECKFLAG(flag, shouldbe)                                              \
    if (!!(status & flag) != !!shouldbe)                                    \
        return printf(                                                         \
            "line %d: " #flag " should be %sset but isn't, [ %02x, %02x] \n",  \
            __LINE__, shouldbe ? "" : "re", (status & flag), shouldbe);

uint8 mem[65536];

int reads, writes;

uint8 read6502(ushort addr) {
    reads++;
    return mem[addr];
}

void write6502(ushort addr, uint8 val) {
    writes++;
    mem[addr] = val;
}

void exec_instruction(uint8 opcode, uint8 op1,
                      uint8 op2) {
    write6502(pc, opcode);
    write6502(pc + 1, op1);
    write6502(pc + 2, op2);

    clockticks6502 = reads = writes = 0;
    step6502();
}

int interrupt() {
    status = 0xff;

    write6502(0xfffa, 0x00);
    write6502(0xfffb, 0x40);
    write6502(0xfffc, 0x00);
    write6502(0xfffd, 0x50);
    write6502(0xfffe, 0x00);
    write6502(0xffff, 0x60);

    // On reset, a 6502 initialises the stack pointer to 0xFD, and jumps to the
    // address at 0xfffc. Also, the interrupt flag is cleared.
    status &= ~0x04;
    reset6502();
    CHECK(sp, 0x00fd);
    CHECK(pc, 0x5000);

    CHECKFLAG(FLAG_INTERRUPT, 1);

    // This IRQ shouldn't fire because the interrupts are disabled
    irq6502();
    CHECK(sp, 0x00fd);
    CHECK(pc, 0x5000);

    // Enable interrupts and try again
    status &= ~0x04;
    irq6502();

    // On IRQ, a 6502 pushes the pc and flags onto the stack and then fetches pc
    // from the vector at 0xFFFE
    CHECK(sp, 0x00fa);
    CHECK(pc, 0x6000);

    CHECKMEM(0x01fd, 0x50);
    CHECKMEM(0x01fc, 0x00);
    CHECKMEM(0x01fb, status & 0xeb);

    CHECKFLAG(FLAG_INTERRUPT, 1);

    // The NMI may fire even when the Interrupt flag is set
    nmi6502();
    CHECK(sp, 0x00f7);
    CHECK(pc, 0x4000);

    CHECKFLAG(FLAG_INTERRUPT, 1);

    return 0;
}

int test_zp() {

    pc = 0x200;
    exec_instruction(0xa5, 0x03, 0x00);

    CHECK(pc, 0x0202);
    CHECK(ea, 0x0003);
    return 0;
}

int test_zpx() {
    x = 1;
    y = 1;
    pc = 0x200;

    exec_instruction(0xb5, 0x03, 0x00); // lda $03,x
    CHECK(pc, 0x0202);
    CHECK(ea, 0x0004);

    exec_instruction(0xb5, 0xff, 0x00); // lda $ff,x
    CHECK(pc, 0x0204);
    CHECK(ea, 0x0000);

    exec_instruction(0xb6, 0x03, 0x00); // lda $03,x
    CHECK(pc, 0x0206);
    CHECK(ea, 0x0004);

    exec_instruction(0xb6, 0xff, 0x00); // ldx $ff,y
    CHECK(pc, 0x0208);
    CHECK(ea, 0x0000);

    return 0;
}

int decimal_mode() {
     

    a = 0x89;
    pc = 0x200;
    status = FLAG_DECIMAL; // Turn on decimal mode, clear carry flag

    exec_instruction(0x69, 0x01, 0x00); // ADC #$01
    CHECK(pc, 0x202);
	CHECK(a, 0x90);
    

    exec_instruction(0x69, 0x10, 0x00); // ADC #$10
    CHECK(pc, 0x204);
    CHECK(a, 0x00);

    exec_instruction(0x18, 0x00, 0x00); // CLC
    CHECK(pc, 0x205);
    CHECKFLAG(FLAG_CARRY, 0);

    exec_instruction(0xe9, 0x01, 0x00); // SBC #$01
    CHECK(pc, 0x207);
    CHECK(a, 0x98); /*The carry bit is not set, so a subtraction should take us down to 98! However, the carry bit *will* be set after this.*/

	/*This instruction starts with the carry bit set, due to the previous instruction.*/
    exec_instruction(0xe9, 0x10, 0x00); // SBC #$10
    CHECK(pc, 0x209);
    CHECK(a, 0x88); /*this is the result.*/
    CHECKFLAG(FLAG_CARRY, 0); /*The carry bit should be 0.*/

    exec_instruction(0x38, 0x00, 0x00); /* SEC*/
    CHECK(pc, 0x20A);
	CHECKFLAG(FLAG_CARRY, 1); /*The carry bit should be 1.*/
	
    exec_instruction(0xe9, 0x04, 0x00); /* SBC #$4*/
    CHECK(pc, 0x20C);
    CHECK(a, 0x84);
	CHECKFLAG(FLAG_CARRY, 0); 
	/*the carry bit is not set so it will subtract 5 even though we tell it o sub 4.*/
    exec_instruction(0xe9, 0x04, 0x00); // SBC #$4
    CHECK(pc, 0x20E);
    CHECK(a, 0x79);
	CHECKFLAG(FLAG_CARRY, 0); 
	/*the carry bit is not set so it will subtract 3 instead of just two.*/
    exec_instruction(0xe9, 0x02, 0x00); // SBC #$2
    CHECK(pc, 0x210);
    CHECK(a, 0x76);
    
    return 0;
}

int binary_mode() {
    a = 0x89;
    pc = 0x200;
    status = 0x00; // Turn off decimal mode, clear carry flag

    exec_instruction(0x69, 0x01, 0x00); // ADC #$01
    CHECK(pc, 0x202);
    CHECK(a, 0x8a);

    exec_instruction(0x69, 0x14, 0x00); // ADC #$10
    CHECK(pc, 0x204);
    CHECK(a, 0x9e);

    exec_instruction(0x18, 0x00, 0x00); // CLC
    CHECK(pc, 0x205);

    exec_instruction(0xe9, 0x01, 0x00); // SBC #$01
    CHECK(pc, 0x207);
    CHECK(a, 0x9c); /*BUG! the carry flag was not set. it should be 9c, not 9d.*/

    exec_instruction(0xe9, 0x10, 0x00); // SBC #$10
    CHECK(pc, 0x209);
    CHECK(a, 0x8c); /*The carry flag still isn't set. We still subtract an extra one.*/

    return 0;
}

int pushpull() {
     
    a = 0x89;
    sp = 0xff;
    pc = 0x0200;
    exec_instruction(0xa9, 0x40, 0x00); // LDA #$40
    exec_instruction(0x48, 0x00, 0x00); // PHA
    CHECK(sp, 0xfe);
    CHECKMEM(0x01ff, 0x40);
    exec_instruction(0xa9, 0x00, 0x00); // LDA #$00
    exec_instruction(0x48, 0x00, 0x00); // PHA
    CHECK(sp, 0xfd);
    CHECKMEM(0x01fe, 0x00);
    exec_instruction(0x60, 0x00, 0x00); // RTS
    CHECK(sp, 0xff);
    CHECK(pc, 0x4001);
    return 0;
}

int rotations() {
     

    a = 0x01;
    status = 0x00;
    pc = 0x0200;
    exec_instruction(0x6a, 0x00, 0x00); // ROR A
    CHECK(a, 0x00);
    CHECK(pc, 0x0201);
    exec_instruction(0x6a, 0x00, 0x00); // ROR A
    CHECK(a, 0x80);
    CHECK(pc, 0x0202);

    a = 0x01;
    status = 0x00;
    pc = 0x0200;
    exec_instruction(0x4a, 0x00, 0x00); // LSR A
    CHECK(a, 0x00);
    CHECK(pc, 0x0201);
    exec_instruction(0x4a, 0x00, 0x00); // LSR A
    CHECK(a, 0x00);
    CHECK(pc, 0x0202);
    return 0;
}

int incdec() {
     
    x = 0x80;
    y = 0x80;

    write6502(0x00, 0x00);
    status = 0x00;
    pc = 0x0200;

    exec_instruction(0xc6, 0x00, 0x00); // DEC $0
    CHECK(pc, 0x0202);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 1);

    exec_instruction(0xe6, 0x00, 0x00); // INC $0
    CHECK(pc, 0x0204);
    CHECKFLAG(FLAG_ZERO, 1);
    CHECKFLAG(FLAG_SIGN, 0);

    exec_instruction(0xe8, 0x00, 0x00); // INX
    CHECK(pc, 0x0205);
    CHECK(x, 0x81);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 1);

    exec_instruction(0x88, 0x00, 0x00); // DEY
    CHECK(pc, 0x0206);
    CHECK(y, 0x7f);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 0);

    x = 0x00;
    exec_instruction(0xca, 0x00, 0x00); // DEX
    CHECK(pc, 0x0207);
    CHECK(y, 0x7f);
    CHECK(x, 0xff);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 1);

    y = 0x00;
    exec_instruction(0xc8, 0x00, 0x00); // INY
    CHECK(pc, 0x0208);
    CHECK(y, 0x01);
    CHECK(x, 0xff);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 0);

    return 0;
}

int branches() {
     
    status = 0x00;
    pc = 0x0200;
    exec_instruction(0x10, 0x60, 0x00); // BPL *+$60
    CHECK(pc, 0x0262);
    exec_instruction(0x30, 0x10, 0x00); // BMI *+$10
    CHECK(pc, 0x0264);
    exec_instruction(0x50, 0x70, 0x00); // BVC *+$70
    CHECK(pc, 0x02d6);
    exec_instruction(0x90, 0x70, 0x00); // BCC *+$70
    CHECK(pc, 0x0348);
    exec_instruction(0xb0, 0x70, 0x00); // BCS *+$70
    CHECK(pc, 0x034a);
    exec_instruction(0x70, 0xfa, 0x00); // BVS *-$06
    CHECK(pc, 0x034c);
    exec_instruction(0xd0, 0xfa, 0x00); // BNE *-$06
    CHECK(pc, 0x0348);
    exec_instruction(0xf0, 0xfa, 0x00); // BEQ *-$06
    CHECK(pc, 0x034a);

    status = FLAG_CARRY | FLAG_ZERO | FLAG_SIGN | FLAG_OVERFLOW;
    exec_instruction(0xb0, 0x70, 0x00); // BCS *+$70
    CHECK(pc, 0x03bc);
    exec_instruction(0xf0, 0xfa, 0x00); // BEQ *-$06
    CHECK(pc, 0x03b8);
    exec_instruction(0x30, 0x10, 0x00); // BMI *+$10
    CHECK(pc, 0x03ca);
    exec_instruction(0x70, 0xfa, 0x00); // BVS *-$06
    CHECK(pc, 0x03c6);
    return 0;
}

int comparisons() {
     
    status = 0x00;
    pc = 0x0200;
    a = 0x50;
    x = 0x00;
    y = 0xc0;

    exec_instruction(0xc9, 0x00, 0x00);
    CHECKFLAG(FLAG_CARRY, 1);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 0);

    exec_instruction(0xc9, 0x51, 0x00);
    CHECKFLAG(FLAG_CARRY, 0);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 1);

    exec_instruction(0xe0, 0x00, 0x00);
    CHECKFLAG(FLAG_CARRY, 1);
    CHECKFLAG(FLAG_ZERO, 1);
    CHECKFLAG(FLAG_SIGN, 0);

    exec_instruction(0xc0, 0x01, 0x00);
    CHECKFLAG(FLAG_CARRY, 1);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 1);

    return 0;
}

int absolute() {
     
    clockticks6502 = 0;
    pc = 0x200;
    exec_instruction(0xad, 0x60, 0x00);
    CHECK(ea, 0x0060);
    CHECK(pc, 0x0203);
    CHECK(clockticks6502, 4);
    return 0;
}

int absolute_x() {
     
    pc = 0x200;
    x = 0x80;
    clockticks6502 = 0;

    exec_instruction(0xbd, 0x60, 0x00);
    CHECK(ea, 0x00e0);
    CHECK(pc, 0x0203);
    CHECK(clockticks6502, 4);

    // Takes another cycle because of page-crossing
    clockticks6502 = 0;
    exec_instruction(0xbd, 0xa0, 0x00);
    CHECK(ea, 0x0120);
    CHECK(pc, 0x0206);
    CHECK(clockticks6502, 5);

    // Should NOT take another cycle because of page-crossing
    clockticks6502 = 0;
    exec_instruction(0x9d, 0x60, 0x00);
    CHECK(ea, 0x00e0);
    CHECK(pc, 0x0209);
    CHECK(clockticks6502, 5);

    clockticks6502 = 0;
    exec_instruction(0x9d, 0xa0, 0x00);
    CHECK(ea, 0x0120);
    CHECK(pc, 0x020c);
    CHECK(clockticks6502, 5);
    return 0;
}

int absolute_y() {
     
    pc = 0x200;
    y = 0x80;
    clockticks6502 = 0;

    exec_instruction(0xb9, 0x60, 0x00);
    CHECK(ea, 0x00e0);
    CHECK(pc, 0x0203);
    CHECK(clockticks6502, 4);

    // Takes another cycle because of page-crossing
    clockticks6502 = 0;
    exec_instruction(0xb9, 0xa0, 0x00);
    CHECK(ea, 0x0120);
    CHECK(pc, 0x0206);
    CHECK(clockticks6502, 5);

    // Should NOT take another cycle because of page-crossing
    clockticks6502 = 0;
    exec_instruction(0x99, 0x60, 0x00);
    CHECK(ea, 0x00e0);
    CHECK(pc, 0x0209);
    CHECK(clockticks6502, 5);

    clockticks6502 = 0;
    exec_instruction(0x99, 0xa0, 0x00);
    CHECK(ea, 0x0120);
    CHECK(pc, 0x020c);
    CHECK(clockticks6502, 5);
    return 0;
}

int indirect() {
     
    pc = 0x200;
    write6502(0x8000, 0x01);
    write6502(0x80fe, 0x02);
    write6502(0x80ff, 0x03);
    write6502(0x8100, 0x04);

    clockticks6502 = 0;
    exec_instruction(0x6c, 0xff, 0x80);
    CHECK(pc, 0x0103);
    CHECK(clockticks6502, 5);

    return 0;
}

int indirect_y() {
     
    pc = 0x200;
    y = 0x80;
    write6502(0x20, 0x81);
    write6502(0x21, 0x20);

    // Takes another cycle because of page-crossing
    clockticks6502 = 0;
    exec_instruction(0xb1, 0x20, 0x00);
    CHECK(ea, 0x2101);
    CHECK(pc, 0x0202);
    CHECK(clockticks6502, 6);

    // Should NOT take another cycle because of page-crossing
    clockticks6502 = 0;
    y = 0x10;
    exec_instruction(0xb1, 0x20, 0x00);
    CHECK(ea, 0x2091);
    CHECK(pc, 0x0204);
    CHECK(clockticks6502, 5);

    // Takes 6 cycles regardless of page-crossing or not
    clockticks6502 = 0;
    y = 0x80;
    exec_instruction(0x91, 0x20, 0x00);
    CHECK(ea, 0x2101);
    CHECK(pc, 0x0206);
    CHECK(clockticks6502, 6);

    // Takes 6 cycles regardless of page-crossing or not
    clockticks6502 = 0;
    y = 0x10;
    exec_instruction(0x91, 0x20, 0x00);
    CHECK(ea, 0x2091);
    CHECK(pc, 0x0208);
    CHECK(clockticks6502, 6);

    return 0;
}

int indirect_x() {
     
    pc = 0x200;
    x = 0x00;
    write6502(0x20, 0x81);
    write6502(0x21, 0x20);
    write6502(0xff, 0x81);
    write6502(0x00, 0x20);

    exec_instruction(0xa1, 0x20, 0x00);
    CHECK(ea, 0x2081);
    CHECK(pc, 0x0202);
    CHECK(clockticks6502, 6);

    x = 0x40;
    exec_instruction(0xa1, 0xe0, 0x00);
    CHECK(ea, 0x2081);
    CHECK(clockticks6502, 6);

    x = 0;
    exec_instruction(0xa1, 0x20, 0x00);
    CHECK(ea, 0x2081);
    CHECK(clockticks6502, 6);

    exec_instruction(0x81, 0xff, 0x00);
    CHECK(ea, 0x2081);
    CHECK(clockticks6502, 6);

    exec_instruction(0x81, 0x20, 0x00);
    CHECK(ea, 0x2081);
    CHECK(clockticks6502, 6);

    return 0;
}

int test_zpi() {
     
    pc = 0x200;
    x = 0x59;
    write6502(0x20, 0x81);
    write6502(0x21, 0x20);
    write6502(0xff, 0x81);
    write6502(0x00, 0x20);

    exec_instruction(0xb2, 0x20, 0x00);
    CHECK(ea, 0x2081);
    CHECK(pc, 0x0202);
    CHECK(clockticks6502, 5);

    x = 0;
    exec_instruction(0xb2, 0x20, 0x00);
    CHECK(ea, 0x2081);
    CHECK(clockticks6502, 5);

    exec_instruction(0x92, 0xff, 0x00);
    CHECK(ea, 0x2081);
    CHECK(clockticks6502, 5);

    exec_instruction(0x92, 0x20, 0x00);
    CHECK(ea, 0x2081);
    CHECK(clockticks6502, 5);

    return 0;
}

int flags() {
     
    pc = 0x200;
    status = 0xff;

    exec_instruction(0x18, 0x00, 0x00);
    CHECKFLAG(FLAG_CARRY, 0);
    exec_instruction(0x38, 0x00, 0x00);
    CHECKFLAG(FLAG_CARRY, 1);

    exec_instruction(0x58, 0x00, 0x00);
    CHECKFLAG(FLAG_INTERRUPT, 0);
    exec_instruction(0x78, 0x00, 0x00);
    CHECKFLAG(FLAG_INTERRUPT, 1);

    exec_instruction(0xd8, 0x00, 0x00);
    CHECKFLAG(FLAG_DECIMAL, 0);
    exec_instruction(0xf8, 0x00, 0x00);
    CHECKFLAG(FLAG_DECIMAL, 1);

    exec_instruction(0xb8, 0x00, 0x00);
    CHECKFLAG(FLAG_OVERFLOW, 0);

    return 0;
}

int loads() {
     
    pc = 0x200;

    exec_instruction(0xa0, 0x00, 0x00); // ldy #$00
    CHECKFLAG(FLAG_ZERO, 1);
    CHECKFLAG(FLAG_SIGN, 0);

    exec_instruction(0xa0, 0x80, 0x00); // ldy #$80
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 1);

    exec_instruction(0xa0, 0x7f, 0x00); // ldy #$7f
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 0);

    exec_instruction(0xa2, 0x00, 0x00); // ldx #$ff
    CHECKFLAG(FLAG_ZERO, 1);
    CHECKFLAG(FLAG_SIGN, 0);

    return 0;
}

int transfers() {
     
    pc = 0x200;
    status = 0x00;

    x = 0x80;

    exec_instruction(0x9a, 0x00, 0x00); // txs
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 0);
    CHECK(sp, 0x80);

    exec_instruction(0x8a, 0x00, 0x00); // txa
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 1);
    CHECK(a, 0x80);

    a = 0x1;
    exec_instruction(0xaa, 0x00, 0x00); // tax
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 0);
    CHECK(x, 0x01);

    exec_instruction(0xba, 0x80, 0x00); // tsx
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 1);
    CHECK(x, 0x80);

    exec_instruction(0xa8, 0x00, 0x00); // tay
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 0);
    CHECK(y, 0x01);

    a = 0x80;
    exec_instruction(0x98, 0x00, 0x00); // tya
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 0);
    CHECK(a, 0x01);

    return 0;
}

int and_opcode() {
     

    a = 0xff;
    status = 0x00;
    pc = 0x200;

    exec_instruction(0x29, 0xe1, 0x00);
    CHECK(a, 0xe1);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 1);
    CHECK(pc, 0x0202);

    exec_instruction(0x29, 0x71, 0x00);
    CHECK(a, 0x61);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 0);

    exec_instruction(0x29, 0x82, 0x00);
    CHECK(a, 0x00);
    CHECKFLAG(FLAG_ZERO, 1);
    CHECKFLAG(FLAG_SIGN, 0);

    return 0;
}

int asl_opcode() {
     

    a = 0x50;
    status = 0x00;
    pc = 0x200;

    exec_instruction(0x0a, 0x00, 0x00);
    CHECK(a, 0xa0);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 1);
    CHECKFLAG(FLAG_CARRY, 0);
    CHECK(pc, 0x0201);

    exec_instruction(0x0a, 0x00, 0x00);
    CHECK(a, 0x40);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 0);
    CHECKFLAG(FLAG_CARRY, 1);

    exec_instruction(0x0a, 0x00, 0x00);
    CHECK(a, 0x80);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 1);
    CHECKFLAG(FLAG_CARRY, 0);

    exec_instruction(0x0a, 0x00, 0x00);
    CHECK(a, 0x00);
    CHECKFLAG(FLAG_ZERO, 1);
    CHECKFLAG(FLAG_SIGN, 0);
    CHECKFLAG(FLAG_CARRY, 1);

    return 0;
}

int bit_opcode() {
     

    a = 0x50;
    status = 0x00;
    pc = 0x200;
    write6502(0xff, 0x80);

    exec_instruction(0x24, 0xff, 0x00);
    CHECK(a, 0x50);
    CHECKFLAG(FLAG_ZERO, 1);
    CHECKFLAG(FLAG_SIGN, 1);
    CHECKFLAG(FLAG_CARRY, 0);
    CHECK(pc, 0x0202);

    a = 0x40;
    write6502(0xff, 0x40);
    exec_instruction(0x2c, 0xff, 0x00);
    CHECK(a, 0x40);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 0);
    CHECKFLAG(FLAG_CARRY, 0);
    CHECK(pc, 0x0205);

    return 0;
}

int bit_imm_opcode() {
     

    a = 0x50;
    status = 0x00;
    pc = 0x200;

    exec_instruction(0x89, 0xff, 0x00);
    CHECK(a, 0x50);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 0); /*originally tested for 0*/
    CHECKFLAG(FLAG_CARRY, 0);
    CHECK(pc, 0x0202);

    exec_instruction(0x89, 0x80, 0x00);
    CHECK(a, 0x50);
    CHECKFLAG(FLAG_ZERO, 1);
    CHECKFLAG(FLAG_SIGN, 0); /*originally tested for 0*/
    CHECKFLAG(FLAG_CARRY, 0);
    CHECK(pc, 0x0204);

    return 0;
}

int brk_opcode() {
     
    reset6502();

    status = FLAG_ZERO | FLAG_SIGN | FLAG_CARRY | FLAG_OVERFLOW;
    pc = 0x200;
    write6502(0xfffe, 0x00);
    write6502(0xffff, 0x60);

    exec_instruction(0x00, 0x00, 0x00);
    CHECKFLAG(FLAG_ZERO, 1);
    CHECKFLAG(FLAG_SIGN, 1);
    CHECKFLAG(FLAG_CARRY, 1);
    CHECKFLAG(FLAG_INTERRUPT, 1);
    CHECKFLAG(FLAG_OVERFLOW, 1);

    CHECK(sp, 0x00fa);
    CHECK(pc, 0x6000);

    CHECKMEM(0x01fd, 0x02);
    CHECKMEM(0x01fc, 0x02);
    CHECKMEM(0x01fb, FLAG_ZERO | FLAG_SIGN | FLAG_CARRY | FLAG_OVERFLOW |
                         FLAG_BREAK | FLAG_CONSTANT);

    return 0;
}

int eor_opcode() {
     
    reset6502();

    status = 0;
    pc = 0x200;
    a = 0xf0;

    exec_instruction(0x49, 0x43, 0x00);
    CHECKFLAG(FLAG_SIGN, 1);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECK(a, 0xb3);

    exec_instruction(0x49, 0xb3, 0x00);
    CHECKFLAG(FLAG_SIGN, 0);
    CHECKFLAG(FLAG_ZERO, 1);
    CHECK(a, 0x00);

    return 0;
}

int jsr_opcode() {
     
    reset6502();

    status = 0;
    pc = 0x300;

    exec_instruction(0x20, 0x43, 0x00); // JSR $0043
    CHECK(pc, 0x0043);

    // check the return address on the stack
    // (Because RTS increments the PC after fetching it, JSR actually pushes
    // PC-1, so we need to check that the return address is $0302)
    CHECK(sp, 0xfb);
    CHECKMEM(0x01fd, 0x03);
    CHECKMEM(0x01fc, 0x02);

    exec_instruction(0x60, 0x00, 0x00); // RTS
    CHECK(sp, 0xfd);
    // (RTS increments the return address, so it's $303, the location
    // immediately after the JSR instruction)
    CHECK(pc, 0x303);

    return 0;
}

int rla_opcode() {
     

    a = 0x23;
    status = 0xf6; // Turn off the carry flag and decimal mode
    write6502(0x01, 0x12);

    pc = 0x200;
    reads = 0;
    writes = 0;
    exec_instruction(0x27, 0x01, 0x00);
/*
    if (reads != 3)
        return printf("rla zero-page did %d reads instead of 3\n", reads);
    if (writes != 2)
        return printf("rla zero-page did %d writes instead of 2\n", writes);
*/
    CHECKMEM(0x01, 0x24);

    CHECK(pc, 0x0202);
    CHECK(ea, 0x0001);
    CHECK(a, 0x20);
    return 0;
}

int rra_opcode() {
    a = 0x3;
    status = 0xf6; // Turn off the carry flag and decimal mode
    write6502(0x01, 0x02);

    pc = 0x200;
    reads = 0;
    writes = 0;
    exec_instruction(0x67, 0x01, 0x00);
/*
    if (reads != 3)
        return printf("rra zero-page did %d reads instead of 3\n", reads);
    if (writes != 2)
        return printf("rra zero-page did %d writes instead of 2\n", writes);
*/
    CHECKMEM(0x01, 0x01);

    CHECK(pc, 0x0202);
    CHECK(ea, 0x0001);
    CHECK(a, 0x04);
    return 0;
}

int nop_opcode() {
     
    pc = 0x200;
    exec_instruction(0xea, 0x00, 0x00); // nop
    return 0;
}

int ora_opcode() {
     
    pc = 0x200;
    a = 0x00;
    exec_instruction(0x09, 0x00, 0x00); // ora #$00
    CHECKFLAG(FLAG_SIGN, 0);
    CHECKFLAG(FLAG_ZERO, 1);
    CHECK(a, 0x00);
    exec_instruction(0x09, 0x01, 0x00); // ora #$01
    CHECKFLAG(FLAG_SIGN, 0);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECK(a, 0x01);
    exec_instruction(0x09, 0x02, 0x00); // ora #$02
    CHECKFLAG(FLAG_SIGN, 0);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECK(a, 0x03);
    exec_instruction(0x09, 0x82, 0x00); // ora #$82
    CHECKFLAG(FLAG_SIGN, 1);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECK(a, 0x83);
    return 0;
}

int rol_opcode() {
     
    pc = 0x200;
    a = 0x20;
    status = 0x00; // Make sure Carry's clear

    exec_instruction(0x2a, 0x00, 0x00); // rol
    CHECKFLAG(FLAG_CARRY, 0);
    CHECKFLAG(FLAG_SIGN, 0);
    CHECK(a, 0x40);

    exec_instruction(0x2a, 0x00, 0x00); // rol
    CHECKFLAG(FLAG_CARRY, 0);
    CHECKFLAG(FLAG_SIGN, 1);
    CHECK(a, 0x80);

    exec_instruction(0x2a, 0x00, 0x00); // rol
    CHECKFLAG(FLAG_CARRY, 1);
    CHECKFLAG(FLAG_SIGN, 0);
    CHECK(a, 0x00);

    exec_instruction(0x2a, 0x00, 0x00); // rol
    CHECKFLAG(FLAG_CARRY, 0);
    CHECKFLAG(FLAG_SIGN, 0);
    CHECK(a, 0x01);
    return 0;
}

int rti_opcode() {
     
    pc = 0x200;
    a = 0x20;
    status = 0x00;
    reset6502();

    CHECK(sp, 0xfd);
    write6502(0x1fe, 0x01);
    write6502(0x1ff, 0x02);
    write6502(0x100, 0x03);

    exec_instruction(0x40, 0x00, 0x00); // rti
    CHECK(sp, 0x00);
    CHECK(pc, 0x0302);
    CHECKFLAG(FLAG_CARRY, 1);
    CHECKFLAG(FLAG_SIGN, 0);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_INTERRUPT, 0);
    CHECKFLAG(FLAG_DECIMAL, 0);
    CHECKFLAG(FLAG_OVERFLOW, 0);

    return 0;
}

int sax_opcode() {
     
    pc = 0x200;
    a = 0x03;
    x = 0x06;
    status = 0x00;
    uint8 address = 0xff;

    write6502(address, 0x03);

    exec_instruction(0x87, address, 0x00); // sax address
    CHECK(pc, 0x0202);
    CHECKMEM(address, 0x02);

    return 0;
}

int sta_opcode() {
     
    pc = 0x200;
    a = 0x20;
    status = 0x00;
    uint8 address = 0xff;

    write6502(address, 0x03);

    exec_instruction(0x85, address, 0x00); // sta address
    CHECK(pc, 0x0202);
    CHECKMEM(address, 0x20);

    return 0;
}

int stx_opcode() {
     
    pc = 0x200;
    x = 0x80;
    status = 0x00;
    uint8 address = 0xff;

    write6502(address, 0x03);

    exec_instruction(0x86, address, 0x00); // sta address
    CHECK(pc, 0x0202);
    CHECKMEM(address, 0x80);

    return 0;
}

int sty_opcode() {
     
    pc = 0x200;
    y = 0x01;
    status = 0x00;
    uint8 address = 0xff;

    write6502(0xff, 0x03);

    exec_instruction(0x84, address, 0x00); // sta address
    CHECK(pc, 0x0202);
    CHECKMEM(address, 0x01);

    return 0;
}

int stz_opcode() {
     
    pc = 0x200;
    status = 0x00;
    uint8 address = 0xff;

    write6502(0xff, 0x03);

    exec_instruction(0x64, address, 0x00); // stz address
    CHECK(pc, 0x0202);
    CHECKMEM(address, 0);

    return 0;
}

int sre_opcode() {
     

    a = 0x3;
    pc = 0x200;
    write6502(0x01, 0x02);

    exec_instruction(0x47, 0x01, 0x00); // LSE $01
    CHECKMEM(0x01, 0x01);

    CHECK(pc, 0x0202);
    CHECK(ea, 0x0001);
    CHECK(a, 0x02);
    return 0;
}

int lax_opcode() {
     
    pc = 0x200;

    write6502(0xab, 0x00);
    exec_instruction(0xa7, 0xab, 0x00); // lax $ab
    CHECKFLAG(FLAG_ZERO, 1);
    CHECKFLAG(FLAG_SIGN, 0);

    write6502(0xab, 0x7b);
    exec_instruction(0xa7, 0xab, 0x00); // lax $ab
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 0);

    write6502(0xab, 0x8a);
    exec_instruction(0xa7, 0xab, 0x00); // lax $ab
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_SIGN, 1);

    return 0;
}

/*
   See this document:
   http://www.zimmers.net/anonftp/pub/cbm/documents/chipdata/6502-NMOS.extra.opcodes
   for information about how illegal opcodes work
*/

int cmos_jmp_indirect() {
     
    pc = 0x200;
    write6502(0x8000, 0x01);
    write6502(0x80fe, 0x02);
    write6502(0x80ff, 0x03);
    write6502(0x8100, 0x04);

    clockticks6502 = 0;
    exec_instruction(0x6c, 0xff, 0x80);
    CHECK(pc, 0x0403);
    CHECK(clockticks6502, 6);

    return 0;
}

int cmos_jmp_absxi() {
     
    pc = 0x0200;
    x = 0xff;
    write6502(0x1456, 0xcd);
    write6502(0x1457, 0xab);
    exec_instruction(0x7c, 0x57, 0x13);
    CHECK(pc, 0xabcd);
    CHECK(clockticks6502, 6);
    return 0;
}

int pushme_pullyou() {
     
    reset6502();
    pc = 0x0200;
    x = 0xff;
    y = 0x01;
    a = 0x00;
    status = 0x00;
    exec_instruction(0xda, 0x0, 0x0); // phx
    CHECK(sp, 0xfc);
    CHECKMEM(0x1fd, 0xff);
    exec_instruction(0x5a, 0x0, 0x0); // phy
    CHECK(sp, 0xfb);
    CHECKMEM(0x1fc, 0x01);
    exec_instruction(0x48, 0x0, 0x0); // pha
    CHECK(sp, 0xfa);
    CHECKMEM(0x1fb, 0x00);
    exec_instruction(0x7a, 0x0, 0x0); // ply
    CHECK(sp, 0xfb);
    CHECK(y, 0x00);
    exec_instruction(0x28, 0x0, 0x0); // plp
    CHECK(sp, 0xfc);
    CHECKFLAG(FLAG_CARRY, 1);
    CHECKFLAG(FLAG_ZERO, 0);
    CHECKFLAG(FLAG_INTERRUPT, 0);
    CHECKFLAG(FLAG_DECIMAL, 0);
    CHECKFLAG(FLAG_SIGN, 0);
    CHECKFLAG(FLAG_OVERFLOW, 0);
    exec_instruction(0x68, 0x0, 0x0); // pla
    CHECK(sp, 0xfd);
    CHECK(a, 0xff);
    exec_instruction(0x08, 0x0, 0x0); // php
    CHECK(sp, 0xfc);
    exec_instruction(0xfa, 0x0, 0x0); // plx
    CHECK(sp, 0xfd);
    CHECK(x, (FLAG_SIGN | FLAG_CARRY | FLAG_CONSTANT | FLAG_BREAK));

    return 0;
}

typedef struct {
    char *testname;
    int (*fp)();
} test_t;

test_t normal_tests[] = {{"interrupts", &interrupt},
                  {"zero page addressing", &test_zp},
                  {"indexed zero page addressing", &test_zpx},
                  {"absolute addressing", &absolute},
                  {"absolute,x addressing", &absolute_x},
                  {"absolute,y addressing", &absolute_y},
                  {"indirect,y addressing", &indirect_y},
                  {"indirect,x addressing", &indirect_x},
                  {"decimal mode", decimal_mode},
                  {"flags set & reset", flags},
                  {"binary mode", binary_mode},
                  {"push & pull", &pushpull},
                  {"rotations", &rotations},
                  {"branches", &branches},
                  {"comparisons", &comparisons},
                  {"increments and decrements", &incdec},
                  {"loads", &loads},
                  {"transfers", &transfers},
                  {"and", &and_opcode},
                  {"asl", &asl_opcode},
                  {"bit", &bit_opcode},
                  {"brk", &brk_opcode},
                  {"eor", &eor_opcode},
                  {"jsr & rts", &jsr_opcode},
                  {"nop", &nop_opcode},
                  {"ora", &ora_opcode},
                  {"rol", &rol_opcode},
                  {"rti", &rti_opcode},
                  {"sta", &sta_opcode},
                  {"stx", &stx_opcode},
                  {"sty", &sty_opcode},
                  {NULL, NULL},
                  };

test_t nmos_tests[] = {{"indirect addressing", &indirect},
                       {"rra", &rra_opcode},
                       {"rla", &rla_opcode},
                       {"sre", &sre_opcode},
                       {"sax", &sax_opcode},
                       {"lax", &lax_opcode},
                       {NULL, NULL}};

test_t cmos_tests[] = {{"CMOS jmp indirect", &cmos_jmp_indirect},
                       {"Immediate BIT", &bit_imm_opcode},
                       {"(absolute,x)", &cmos_jmp_absxi},
                       {"(zp) addressing", &test_zpi},
                       {"pushes and pulls", &pushme_pullyou},
                       {"stz", &stz_opcode},
                       {NULL, NULL}};

int run_tests(test_t tests[]) {
	int i;
    for (i = 0; tests[i].fp != NULL
		&& tests[i].testname != NULL; i++
	)
    {
    	
    	if(tests[i].testname == NULL)break;
		if(tests[i].fp){
	        if (tests[i].fp()) {
	            printf("\033[0;31m%s failed\033[0m\n", tests[i].testname);
	            exit(1);
	        }
	        printf("\033[0;33m%s okay\033[0m\n", tests[i].testname);
        }
    }
    printf("\r\n<DONE TESTING>\r\n");
    return 0;
}

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
    run_tests(normal_tests);
    run_tests(cmos_tests);
    /*
    if(argc > 1)
    	if (!strcmp(argv[1], "cmos"))
        	run_tests(cmos_tests);
    */
        	
    return EXIT_SUCCESS;
}

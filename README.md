# Fake6502, revamped

Mike Chambers' Fake6502 with revamped bug fixes for decimal mode, along with a few other fixes.

The header file in this repository is in the public domain. tests.c is not. Do not put it in a public domain project.


I used ![this](https://github.com/omarandlorraine/fake6502) instruction exerciser along with 
![this](https://github.com/mist64/kernalemu) C64 kernal emulator to verify that my fixes were correct and
did not break anything.

Commodore basic v2 boots and can run prints and write programs. 
If you break the emulator with a fix, then you'll typically get a SYNTAX ERROR
from every command, and hitting enter without any text will hang the emulator.

I have yet to verify that this emulator works with MOARNES, mike chamber's NES emulator.
However, given that the NES's 6502 variant does not use decimal mode, I would guess
that it would still work just fine.

Moarnes can be found on github ![here](https://github.com/darlanalves/moarnes) 

or on sourceforge, ![here](https://sourceforge.net/projects/moarnes/)

The latter is supposedly "more official"

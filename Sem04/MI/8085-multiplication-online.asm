;<Multiplication of two 8-bit num, Anurag Verma>

;LDA 2200H ; Copy the contents from memory location 2200H to accumulator
MVI A, 2H ; --

MOV E, A ; Copy accumulator to register E

MVI D, 00H ; Get the first number in DE register pair

;LDA 2201H ; Copy the contents from memory location 2201H to accumulator
MVI A,3H ; --

MOV C, A ; Initialize counter by value of multiplier

LXI H, 0000H ; Result = 0

BACK:DAD D ; Result = result + first number

DCR C ; Decrement counter

JNZ BACK ; If count≠0 (i.e. Zero flag≠0) repeat the loop

SHLD 0000H ; Store value of H at memory location 2202H and L at 2203H

HLT ; Terminate program execution.

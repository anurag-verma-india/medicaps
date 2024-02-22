;<Multiplication of two 8-bit num, Anurag Verma>

MVI C, 4H
MVI E, 3H

MVI D, 00H

MVI H, 00H ; RESULT IN H initial 0

LOOP:DAD D

BACK:DAD D ; Result = result + first number

DCR C ; Decrement counter

JNZ LOOP ; If count≠0 (i.e. Zero flag≠0) repeat the loop

SHLD 0000H

HLT
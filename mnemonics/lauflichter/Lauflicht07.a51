ORG 8000h
P4 EQU 0C0h
LED EQU P1
schalter EQU P4
laden BIT P3.2
mov LED,#0

start:    jb laden,skip
          mov a,schalter
skip:     rlc A
          mov LED,A
          acall zeit
          jsmp start

zeit:     mov R3,#10
loop1:    mov R2,#200
loop2:    mov R1,#250
loop3:    djnz R1,loop3
          djnz R2,loop2
          djnz R3,loop1
          ret
END

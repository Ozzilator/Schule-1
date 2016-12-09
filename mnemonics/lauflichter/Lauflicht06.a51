ORG 8000h
LED EQU P1
P4 EQU 0C0h
mov A,#0
setb C

links:    rlc A
          mov LED,A
          mov R3,P4
          acall time
          jnc links
          
rechts:   rrc A
          mov LED,A
          mov R3,P4
          acall time
          jnc rechts
          sjmp links
          
time:     
loop3:    mov R1,#250
loop1:    mov R2,#200
loop2:    djnz R2,loop2
          djnz R1,loop1
          djnz R3,loop3
          ret
END

ORG 8000h
LED EQU P1
mov A,#0
setb C

links:    rlc A
          mov LED,A
          acall zeit
          jnc links
          
rechts:   rrc A
          mov LED,A
          avall zeit
          jnc rechts
          sjmp links
 
zeit:     mov R1,#250; 100ms break
loop1:    mov R2,#200
loop2:    djnz R2,loop2
          djnz R1,loop1
          ret
END

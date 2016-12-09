ORG 8000h
LED EQU P1
mov A,#0
setb C
  
  Start:  rcl A
          mov LED,A
          acall Zeit
          sjmp Start
  
  Zeit:   mov R1,#250; 100ms break
  loop1:  mov R2,#200
  loop2:  djnz R2,loop2
          djnz R1,loop1
  ret
END

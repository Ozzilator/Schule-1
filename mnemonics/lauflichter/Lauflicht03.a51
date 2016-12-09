ORG 8000h
LED EQU P1
richtung BIT P3.2
mov A,#0
setb C
    
    start:  jnb richtung,links
    rechts: rrc A
            mov LED,A
            acall zeit
            sjmp start
    links:  rcl A
            mov LED,A
            acall zeit
            sjmp start
    
    zeit:   mov R1,#250; 100ms break
    loop1:  mov R2,#200
    loop2:  djnz R2,loop2
            djnz R1,loop1
    ret
END          

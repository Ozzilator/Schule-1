ORG 8000h
LED       DATA P1
richtung  BIT P3.2
merker    BIT 00h
mov A,#0
setb C

start:    jb richtung,laufe         ;lauflicht läuft
warthigh: jnb richtung,warthigh     ;warten bis taster losgelassen wird
          cpl merker                ;richtung ändern
          jmp start
          
laufe:    jnb merker,links          ;merker == 0 --> links
rechts:   rrc A                     ;merker == 1 --> rechts
          mov LED,A
          acall zeit
          jmp start
links:    rlc A
          mov LED,A
          acall zeit
          jmp start
zeit:     mov R1,#250                ;100ms break
loop1:    mov R2,#200
loop2:    djnz R2,loop2
          djnz R1,loop1
          ret
END

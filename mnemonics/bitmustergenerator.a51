ORG 8000h
P4 EQU 0C0h

;Muster1
mov 001h, #00000000b
mov 002h, #11111111b
mov 003h, #01111111b
mov 004h, #00111111b
mov 005h, #00011111b
mov 006h, #00001111b
mov 007h, #00000111b
mov 008h, #00000011b
mov 009h, #00000001b

;Muster2
mov 00ah, #00000000b
mov 00bh, #11111111b
mov 00ch, #11111110b
mov 00dh, #11111100b
mov 00eh, #11111000b
mov 00fh, #11110000b
mov 010h, #11100000b
mov 011h, #11000000b
mov 012h, #10000000b

;Muster3
mov 013h, #00000000b
mov 014h, #11111111b
mov 015h, #00111100b
mov 016h, #00111100b
mov 017h, #00011000b

;Muster4
mov 018h, #00000000b
mov 019h, #00011000b
mov 01ah, #00111100b
mov 01bh, #01111110b
mov 01ch, #11111111b

;TODO
;-fix the the output pattern 
;-add comments for scholz
; the output is correct if you are only looking at the hex adresses. but the table seems to have a bug...

;ALREADY WORKING
;-time is adjustable via p1.0, p1.1, p1.2 and p1.3

Warten_auf_Eingabe:		jb p1.4,Muster1
				jb p1.5,Muster2
				jb p1.6,Muster3
				jb p1.7,Muster4
				jmp Warten_auf_Eingabe

Muster1:			mov r0, #09h
abfrage1: 			mov p2,@r0
				dec r0
				acall sleeperino
				cjne r0,#01h, abfrage1
				jmp Warten_auf_Eingabe

Muster2:			mov r0,#012h
abfrage2: 			mov p2,@r0
				dec r0
				acall sleeperino
				cjne r0,#0ah, abfrage2
				jmp Warten_auf_Eingabe

Muster3:			mov r0,#017h
abfrage3: 			mov p2,@r0
				dec r0
				acall sleeperino
				cjne r0,#013h, abfrage3
				jmp Warten_auf_Eingabe

Muster4:			mov r0,#01ch
abfrage4: 			mov p2,@r0
				dec r0
				acall sleeperino
				cjne r0,#018h, abfrage4
				jmp Warten_auf_Eingabe

;Unterprogramm Zeit 
sleeperino:			mov a, p1
				anl a,#00001111b
				
				mov r3,a
zeit1: 				mov r1,#250
zeit2:				mov r2,#200
zeit3:				djnz r2,zeit3
				djnz r1,zeit2
				djnz r3,zeit1
				ret
END

ORG 8000h
P4 EQU 0C0h

;Muster1
mov 01h, #00000000b
mov 02h, #11111111b
mov 03h, #01111111b
mov 04h, #00111111b
mov 05h, #00011111b
mov 06h, #00001111b
mov 07h, #00000111b
mov 08h, #00000011b
mov 09h, #00000001b

;Muster2
mov 0A0h, #00000000b
mov 0A1h, #11111111b
mov 0A2h, #11111110b
mov 0A3h, #11111100b
mov 0A4h, #11111000b
mov 0A5h, #11110000b
mov 0A6h, #11100000b
mov 0A7h, #11000000b
mov 0A8h, #10000000b

;Muster3
mov 0A9h, #00000000b
mov 0AAh, #11111111b
mov 0ABh, #00111100b
mov 0ACh, #00111100b
mov 0ADh, #00011000b

;Muster4
mov 0AEh, #00000000b
mov 0AFh, #00011000b
mov 0B0h, #00111100b
mov 0B1h, #01111110b
mov 0B2h, #11111111b


;TODO
;-fix the the output pattern 
;-add comments for scholz

;ALREADY WORKING
;-time is adjustable via p1.0, p1.1, p1.2 and p1.3

Warten_auf_Eingabe:		jnb p1.4,Muster1
						  	      jnb p1.5,Muster2
						          jnb p1.6,Muster3
						          jnb p1.7,Muster4
						          jmp Warten_auf_Eingabe

Muster1:			        mov r0, #09h
abfrage1: 			      mov p2,@r0
					            dec r0
					            acall sleeperino
					            cjne r0,#01h, abfrage1
					            jmp Warten_auf_Eingabe

Muster2:			        mov r0,#0A8h
abfrage2: 			      mov p2,@r0
					            dec r0
					            acall sleeperino
					            cjne r0,#0A0h, abfrage2
					            jmp Warten_auf_Eingabe

Muster3:			        mov r0,#0ADh
abfrage3: 			      mov p2,@r0
					            dec r0
					            acall sleeperino
					            cjne r0,#0A9h, abfrage3
					            jmp Warten_auf_Eingabe

Muster4:			        mov r0,#0B2h
abfrage4: 			      mov p2,@r0
					            dec r0
					            acall sleeperino
					            cjne r0,#0AEh, abfrage4
					            jmp Warten_auf_Eingabe

;Unterprogramm Zeit 
sleeperino:			      mov a, p1
					            anl a,#00001111b
					            mov r3,a
zeit1: 				        mov r1,#250
zeit2:				        mov r2,#200
zeit3:				        djnz r2,zeit3
					            djnz r1,zeit2
					            djnz r3,zeit1
					             ret
END

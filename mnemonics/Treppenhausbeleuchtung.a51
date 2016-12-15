org 8000h
P4 equ 0C0h
lampe equ P1
taster equ P3.2
faktor equ 0Ah 									;P4 ist der eigentliche wert --> hardware fehlt

;###############################################
start:			mov lampe,#00h 					;grundstellung
				setb taster
				
taster11:		jb taster,taster11				;taster gedrückt?
				mov lampe,#01h					;lampe ein
				acall zeit
taster12:		jnb taster,taster12				;taster losgelassen?
				acall zeit
				
				mov R3,#faktor					;zeitverz.konst anfangswert
taster21:		jnb taster,lampeaus				;wenn taster erneut gedrückt, lampe sofort aus
				acall zeit
				dec R3							;faktor um eins erniedrigen
				cjne r3,#00,taster21			;wenn faktor != null --> springe zu erneuter abfrage
lampeaus:		mov lampe,#00h					;lampe aus
				acall zeit
taster22:		jnb taster,taster22				;taster losgelassen?
				jmp start
;###############################################

zeit:			mov R1,#250	; 100ms time loop
loop1:			mov R2,#200
loop2:			djnz R2,loop2
				djnz R1,loop1
				ret
END

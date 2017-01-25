;Author: Felix Zimmermann // Niklas Gauder
;Name:   Bitmustergenerator

;ORG 8000h
P4 EQU 0C0h

;Muster1				Tabelle für Bitmuster
mov 01Dh, #00h		
mov 01Eh, #0FFh		
mov 01Fh, #7Fh		
mov 020h, #3Fh	
mov 021h, #1Fh		
mov 022h, #0Fh		
mov 023h, #07h
mov 024h, #03h
mov 025h, #01h

;Muster2
mov 026h, #00h
mov 027h, #0FFh
mov 028h, #0FEh
mov 029h, #0FCh
mov 02ah, #0F8h
mov 02bh, #0F0h
mov 02ch, #0E0h
mov 02dh, #0C0h
mov 02eh, #80h

;Muster3
mov 02fh, #00h
mov 030h, #0FFh
mov 031h, #7Eh
mov 032h, #3Ch
mov 033h, #18h

;Muster4
mov 034h, #00h
mov 035h, #18h
mov 036h, #3Ch
mov 037h, #7Eh
mov 038h, #0FFh
Warten_auf_Eingabe:		jb p1.4,Muster1			;oder-Abfrage der Muster
				jb p1.5,Muster2
				jb p1.6,Muster3
				jb p1.7,Muster4
				jmp Warten_auf_Eingabe

Muster1:			mov r0,#025h			; r0 mit dem höchsten wert des tabellenabschnittes laden
abfrage1: 			mov p2,@r0			; bitmuster an p2 ausgeben
				dec r0				; um einen tabellenplatz verringern
				acall sleep			; sleep
				cjne r0,#01Dh,abfrage1		; abfrage ob tabellenende
				jmp Warten_auf_Eingabe		; zurück zu oderauswahl springen

Muster2:			mov r0,#02eh
abfrage2: 			mov p2,@r0
				dec r0
				acall sleep
				cjne r0,#026h,abfrage2
				jmp Warten_auf_Eingabe

Muster3:			mov r0,#033h
abfrage3: 			mov p2,@r0
				dec r0
				acall sleep
				cjne r0,#02fh,abfrage3
				jmp Warten_auf_Eingabe

Muster4:			mov r0,#038h
abfrage4: 			mov p2,@r0
				dec r0
				acall sleep
				cjne r0,#034h,abfrage4
				jmp Warten_auf_Eingabe

;Unterprogramm Zeit 
sleep:				mov a,p1
				anl a,#00001111b
				
				mov r3,a
zeit1: 				mov r1,#250
zeit2:				mov r2,#200
zeit3:				djnz r2,zeit3
				djnz r1,zeit2
				djnz r3,zeit1
				ret
END

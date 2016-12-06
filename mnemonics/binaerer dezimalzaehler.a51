;ORG 8000h
P4 EQU 0C0h
	
			    MOV R0,#00h			    ;r0 zurücksetzen
eins:		  JNB P3.2,eins		    ;tasterabfrage
			    MOV p2,R0			      ;ausgabe von r0 nach p2
			    ACALL Sekunde		    ;aufruf unterprogramm sekunde
			    INC R0				      ;r0 um eins erhöhen
			    CJNE R0,#0Ah, eins	;sprung nach eins: wenn r0 ungleich 10 -->abbruch von programm, wenn r0 = 10
			    MOV R0,#00h			    ;r0 zurücksetzen
			    JMP eins			      ;rücksprung nach eins
		
Sekunde:	MOV R3,#10			    ;register setzen
Seins:		MOV R2,#200			    ;register setzen
Szwei:		MOV R1,#250			    ;register setzen
Sdrei:		DJNZ R1,Sdrei		    ;schleife1
			    DJNZ R2,Szwei		    ;schleife2
			    DJNZ R3,Seins		    ;schleife3
			    RET
END

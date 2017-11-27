org 8000h
p4 equ 0C0h

start:      mov a,#00h
		        mov r0,#00h
		        jb p4.0,halb
		        jb p4.1,halb_links
		        jb p4.2,ganz
		        jb p4.3,ganz_links
		        jmp start
		
halb:	      mov dptr,#tabelle_halb
jmp ausgabe_07
halb_links: mov dptr,#tabelle_halb_links
jmp ausgabe_07
ganz:	      mov dptr,#tabelle_ganz
jmp ausgabe_04
ganz_links:	mov dptr,#tabelle_ganz_links
jmp ausgabe_04

ausgabe_07:
		        mov a,r0
		        movc a,@a+dptr
		        mov p1,a
		        inc r0
		        acall zeit
		        cjne r0,#07h,ausgabe_07
		        jmp start

ausgabe_04:
		        mov a,r0
		        movc a,@a+dptr
		        mov p1,a
		        inc r0
		        acall zeit
		        cjne r0,#04h,ausgabe_04
		        jmp start

tabelle_halb:	DB 09h,08h,0Ah,02h,06h,04h,05h,01h
tabelle_ganz:	DB 09h,0Ah,06h,05h		
tabelle_halb_links: DB 01h, 05h, 04h, 06h, 02h, 0Ah, 08h, 09h
tabelle_ganz_links: DB 05h, 06h, 0Ah, 09h

;Unterprogramm Zeit 100ms
zeit: 	  mov R1,#100
zeit1:	  mov R2,#25
zeit2:	  djnz R2,zeit2
		      djnz R1,zeit1
          ret		
END	

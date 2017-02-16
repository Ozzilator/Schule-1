ORG 8000h
P4 EQU 0C0h

mov 50h,#09h
mov 51h,#08h
mov 52h,#0Ah
mov 53h,#02h
mov 54h,#06h
mov 55h,#04h
mov 56h,#05h
mov 57h,#01h

start:		mov r0,#50h
start1:		mov p4,@r0
			    acall zeit
			    inc r0
			    cjne r0,#57h,start1
			    jmp start


zeit:		  mov r1,#250		; 100ms time loop
loop1:		mov r2,#100
loop2:		djnz r2,loop2
			    djnz r1,loop1
			    ret
END

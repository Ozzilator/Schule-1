ORG 8000h
P4 EQU 0C0h

mov 50h,#09h
mov 51h,#0Ah
mov 52h,#06h
mov 53h,#05h

start:		mov r0,#50h
start1:		mov p4,@r0
		acall zeit
		inc r0
		cjne r0,#54h,start1
		jmp start


zeit:		mov r1,#250		; 100ms time loop
loop1:		mov r2,#100
loop2:		djnz r2,loop2
		djnz r1,loop1
		ret
END

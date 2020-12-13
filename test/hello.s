		global		start

		section		.text
pstr1:	mov			rax, 0x02000004
		mov			rdi, 1
		mov			rsi, str1
		mov			rdx, 19
		syscall
		ret

pstr2:	mov			rax, 0x02000004
		mov			rdi, 1
		mov			rsi, str2
		mov			rdx, 7
		syscall
		ret
getname:	
		mov			rax, 0x2000003
		mov			rdi, 0
		mov			rsi, name
		mov			rdx, 16
		syscall
		ret

printname:
		mov			rax, 0x2000004
		mov			rdi, 1
		mov			rsi, name
		mov			rdx, 16
		syscall
		ret

start:	
		call pstr1
		call getname
		call pstr2
		call printname; subroutine

		mov			rax, 0x2000001
		mov			rdi, 0
		syscall

		section		.data
str1:	db			"what is your name? "
str2:	db			"hello, "

		section		.bss
		name		resb 16


	

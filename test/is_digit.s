		global		start

		section		.text
start:	
		add			rax, 48
		mov			[digit], al
		mov			rax, 0x2000004
		mov			rdi, 1
		mov			rsi, digit
		mov			rdx, 2
		syscall

		mov			rax, 0x2000001
		mov			rdi, 1
		syscall

		section		.data
digit	db			'0', 10

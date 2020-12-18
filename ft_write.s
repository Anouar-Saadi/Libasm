				global			_ft_write

				SYS_WRITE		equ 0x2000004
				extern			___error
				section			.text

_ft_write:
				mov				rax, SYS_WRITE
				syscall
				jc				_error
				ret

_error:
				push			rax
				call			___error
				pop				qword [rax]
				mov				rax, -1
				ret

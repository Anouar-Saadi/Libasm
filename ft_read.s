				global			_ft_read

				SYS_READ		equ	0x2000003
				extern			___error
				section			.text

_ft_read:
				mov				rax, SYS_READ
				syscall
				jc				_error
				ret

_error:
				push			rax
				call			___error
				pop				qword [rax]
				mov				rax, -1
				ret

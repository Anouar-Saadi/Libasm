				global			_ft_strcmp

				section			.text

_ft_strcmp:	
				mov				rax, 0

_loop:
				xor				rcx, rcx
				xor				rdx, rdx
				mov				byte cl, [rdi + rax]
				mov				byte dl, [rsi + rax]
				inc				rax
				cmp				cl, 0
				je				_end_00
				cmp				dl, 0
				je				_end_02
				cmp				byte cl, byte dl
				je				_loop
				jl				_end_01
				jg				_end_02

_end_00:
				cmp				dl, 0
				jne				_end_01
				mov				rax, 0
				ret

_end_01:
				mov				rax, -1
				ret

_end_02:
				mov				rax, 1
				ret

				global			_ft_strcmp

				section			.text

_ft_strcmp:	
				mov				rax, 0

loop:
				xor				rcx, rcx
				xor				rdx, rdx
				mov				byte cl, [rdi + rax]
				mov				byte dl, [rsi + rax]
				inc				rax
				cmp				cl, 0
				je				end_00
				cmp				dl, 0
				je				end_02
				cmp				byte cl, byte dl
				je				loop
				jl				end_01
				jg				end_02

end_00:
				cmp				dl, 0
				jne				end_01
				mov				rax, 0
				ret

end_01:
				mov				rax, -1
				ret

end_02:
				mov				rax, 1
				ret

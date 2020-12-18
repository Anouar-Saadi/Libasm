					global			_ft_strdup

					extern			_malloc
					extern			_ft_strlen
					extern			_ft_strcpy
					section			.text

_ft_strdup:
					push			rdi
					call			_ft_strlen
					pop				rdi
					inc				rax
					mov				rcx, rdi
					mov				rdi, rax
					push			rcx
					sub				rsp, 32
					call			_malloc
					add				rsp, 32
					cmp				rax, 0
					je				_end
					pop				rcx
					mov				rdi, rax
					mov				rsi, rcx
					call			_ft_strcpy

_end:
					ret

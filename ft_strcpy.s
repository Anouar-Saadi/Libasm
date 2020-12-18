			global		_ft_strcpy

			section		.text

_ft_strcpy:
			xor			rcx, rcx

_ft_cpy:
			xor			rdx, rdx
			cmp			[rsi + rcx], byte 0
			je			_ft_end
			mov			byte dl, [rsi + rcx]
			mov			[rdi + rcx], byte dl
			inc			rcx
			jmp			_ft_cpy

_ft_end:
			mov			[rdi + rcx], byte 0
			mov			rax, rdi
			ret

_ft_null:
			xor			rax, rax
			ret

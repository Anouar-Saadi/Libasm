			global		_ft_strlen

			section		.text

_ft_strlen:
			xor			rax, rax
			mov			rdx, rdi
			xor			rsi, rsi
			cmp			[rdx], byte 0
			jne			_ft_count
			je			_ft_end

_ft_count:
			inc			rdx
			inc			rsi
			cmp			[rdx], byte 0
			jne			_ft_count
			je			_ft_end

_ft_end:
			mov			rax, rsi
			ret

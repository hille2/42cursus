global _ft_strlen

section .text
_ft_strlen:
			xor rax, rax
loop:		
			mov cl, [rdi + rax]
			cmp cl, 0
			je end
			inc	rax
			jmp loop
end:
			ret
global _ft_strcpy

section .text
_ft_strcpy:
			xor rcx, rcx ; очищаем регистр, сбрасываем все биты в 0
loop:		
			mov dl, [rsi + rcx]
			cmp dl, 0
			je end
			mov [rdi + rcx], dl
			inc rcx
			jmp loop
end:
			mov [rdi + rcx], dl
			mov rax, rdi
			ret
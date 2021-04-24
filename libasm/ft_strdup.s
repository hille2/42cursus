global _ft_strdup

section .text
extern ___error
extern _ft_strlen
extern _ft_strcpy
extern _malloc

_ft_strdup:
			xor rax, rax
			call _ft_strlen
			inc rax
			push rdi
			mov rdi, rax
			call _malloc
			cmp rax, 0
			je error
			pop rsi
			mov rdi, rax
			call _ft_strcpy
			jmp end
error:
			call ___error
			mov rax , -1
			ret
end:
			ret


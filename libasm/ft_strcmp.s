global _ft_strcmp

section .text
_ft_strcmp:
			xor rax, rax
			xor rcx, rcx
loop:
			mov dl, [rsi + rcx]
			mov bl, [rdi + rcx]
			cmp rdx, rbx
			jg more
			jl less
			cmp bl, 0
			je equal
			inc rcx
			jmp loop
less:
			mov rax, 1
			ret
more:
			mov rax, -1
			ret
equal:
			ret

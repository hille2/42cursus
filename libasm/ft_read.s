global _ft_read

section .text
extern ___error

_ft_read:
			xor rax, rax
			mov rax, 0x2000003
			syscall
			jc error
			jmp end
end:
			ret
error:		
			push rbx
			mov rdx, rax
			call ___error
			mov [rax], rdx
			mov rax , -1
			pop rdx
			ret
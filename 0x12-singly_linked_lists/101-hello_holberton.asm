section .data
	msg db "Hello, Holberton", 0
	fmt db "%s\n", 0

section .text
	global main
	extern printf

main:
	push rbx		; save rbx register
	mov rbx, msg		; load address of message into rbx
	mov rax, 0		; clear rax register
	push rax		; push 0 onto stack (for printf's return value)
	push rbx		; push address of message onto stack (for printf's format string)
	mov rax, fmt		; load address of format string into rax
	call printf		; call printf
	add rsp, 16		; adjust stack pointer to clean up pushed values
	pop rbx			; restore rbx register
	xor eax, eax		; return 0
	ret


section .data
name db 10,"My name is aaron"
namelen equ $-name
college db 10,"My College is MITWPU"
collegelen equ $-college

section .bss

section .text

global _start

_start:

mov rax,1
mov rdi,1
mov rsi,name
mov rdx,namelen
syscall

mov rax,1
mov rdi,1
mov rsi,college
mov rdx,collegelen
syscall

mov rax,60
mov rdi,0
syscall

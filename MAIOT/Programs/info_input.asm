section .data
m1 db "Enter your name:"
l1 equ $-m1

m2 db "Enter your College:"
l2 equ $-m2

m3 db "Your name is:"
l3 equ $-m3

m4 db "Your college is:"
l4 equ $-m4

m5 db "Enter your Roll no.:"
l5 equ $-m5

m6 db "Your Roll No. is:"
l6 equ $-m6


section .bss
n resb 20
clg resb 20
roll resb 20

section .text

global _start

_start:

mov rax,1
mov rdi,1
mov rsi,m1
mov rdx,l1
syscall

mov rax,0
mov rdi,0
mov rsi,n
mov rdx,20
syscall

mov rax,1
mov rdi,1
mov rsi,m2
mov rdx,l2
syscall

mov rax,0
mov rdi,0
mov rsi,clg
mov rdx,20
syscall

mov rax,1
mov rdi,1
mov rsi,m5
mov rdx,l5
syscall

mov rax,0
mov rdi,0
mov rsi,roll
mov rdx,20
syscall

mov rax,1
mov rdi,1
mov rsi,m3
mov rdx,l3
syscall

mov rax,1
mov rdi,1
mov rsi,n
mov rdx,20
syscall

mov rax,1
mov rdi,1
mov rsi,m4
mov rdx,l4
syscall

mov rax,1
mov rdi,1
mov rsi,clg
mov rdx,20
syscall

mov rax,1
mov rdi,1
mov rsi,m6
mov rdx,l6
syscall

mov rax,1
mov rdi,1
mov rsi,roll
mov rdx,20
syscall

mov rax,60
mov rdi,0
syscall

%macro operate 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .data
msg1 db "Error:",10
msgl1 equ $-msg1
msg2 db "File Copied Successfully",10
msgl2 equ $-msg2

section .bss
fname1 resb 15
fd1 resq 1
fname2 resb 15
fd2 resq 1
buff resb 1024
bufflen resq 1

section .text
global _start
_start:
pop r8 ; command line args are stored in the r8 register
cmp r8,3 ; check if 3 arguments were given (./fname one.txt two.txt) 
jne err ; if 3 args are not given then jump to the err label
pop r8 ; pop the second (arg2)
pop r8 ; pop the first (arg1)

mov rsi,fname1 ; (copy the full file name till the null string is reached)

above:
mov al,[r8]; (first .txt) so f will be moved to rsi then i and so on
cmp al,00; if al is 00 then we know that the null character was loaded in al
je next
mov [rsi],al
inc r8
inc rsi
jmp above ; the point of the above loop was to copy name of source file into fname1

next:
pop r8
mov rsi,fname2

above2:
mov al,[r8]
cmp al,00
je next2
mov [rsi],al
inc r8 
inc rsi
jmp above2

next2:
operate 2,fname1,000000q,0777q ; 000000q means read-mode and 0777q is read write exec perm
mov [fd1],rax

operate 0,[fd1],buff,1024 ; read the first file
mov [bufflen],rax


operate 85,fname2,0777q,0 ; create the second file (85)
operate 2,fname2,2,0777q ; open second file
mov [fd2],rax

operate 1,[fd2],buff,[bufflen] ; write into the Second file
operate 3,[fd2],0,0 ; close the second file
operate 3,[fd1],0,0 ; close the first file

operate 1,1,msg2,msgl2
jmp end

err:
operate 1,1,msg1,msgl1
end:
operate 60,0,0,0

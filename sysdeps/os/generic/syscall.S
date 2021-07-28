// System Call for my operating system (int 80h)
.global syscall
syscall:
    movq    %rdi, %rax
    movq    %rsi, %rdi
    movq    %rdx, %rsi
    movq    %rcx, %rdx
    movq    %r8, %r10
    movq    %r9, %r8
    movq    8(%rsp),%r9
    int     $0x80
    ret

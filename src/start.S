.section rodata
.extern kernel_main, kernel_stack

.section ".text"
.code32
.global "_start"

#include "kdefs.h"

_start:
    cli
    mov $kernel_stack + KERNEL_STACK_SIZE, %esp
    push %eax
    push %ebx
    call kernel_main
    cli
hang:
    hlt
    jmp hang

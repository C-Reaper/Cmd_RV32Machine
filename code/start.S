.section .text.entry
.global _start
.type _start, @function
.global RV32_Exit
.type RV32_Exit, @function

_start:
    la sp, __stack_top
    call main
    call RV32_Exit
1:
    j 1b

.size _start, .-_start

RV32_Exit:
    li t0, 0x10001000
    sw a0, 0(t0)
    ret

.size RV32_Exit, .-RV32_Exit
ENTRY(_start)

MEMORY
{
    RAM (rwx) : ORIGIN = 0x80000000, LENGTH = 16M
}

SECTIONS
{
    .text :
    {
        . = ALIGN(4);

        KEEP(*(.text.entry))
        *(.text*)
    } > RAM

    .rodata :
    {
        . = ALIGN(4);
        *(.rodata*)
    } > RAM

    .data :
    {
        . = ALIGN(4);
        *(.data*)
    } > RAM

    .bss :
    {
        . = ALIGN(4);

        __bss_start = .;

        *(.bss*)
        *(COMMON)

        __bss_end = .;
    } > RAM

    . = ALIGN(16);

    __stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
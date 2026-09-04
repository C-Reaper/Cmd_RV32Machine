ENTRY(_start)

MEMORY
{
    RAM (rwx) : ORIGIN = 0x80000000, LENGTH = 16M
}

PHDRS
{
    text PT_LOAD FLAGS(5); /* read + execute */
    data PT_LOAD FLAGS(6); /* read + write */
}

SECTIONS
{
    .text :
    {
        . = ALIGN(4);

        KEEP(*(.text.entry))
        *(.text*)
    } > RAM :text

    .rodata :
    {
        . = ALIGN(4);
        *(.rodata*)
    } > RAM :text

    . = ALIGN(CONSTANT(MAXPAGESIZE));

    .data :
    {
        . = ALIGN(4);
        *(.data*)
    } > RAM :data

    .bss :
    {
        . = ALIGN(4);

        __bss_start = .;

        *(.bss*)
        *(COMMON)

        __bss_end = .;
    } > RAM :data

    . = ALIGN(16);

    __stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
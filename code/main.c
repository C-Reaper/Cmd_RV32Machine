#include <stdint.h>

volatile uint8_t* UART = (uint8_t*)0x10000000;

static void putc(char c){
    *UART = (uint8_t)c;
}

static void puts(const char *s){
    while (*s)
        putc(*s++);
}

int main(void){
    puts("Hello from RISC-V!\n");

    uint32_t a = 123;
    uint32_t b = 456;
    uint32_t c = a + b;

    if (c == 579)
        puts("ADD: OK\n");
    else
        puts("ADD: FAIL\n");

    return 0;
}
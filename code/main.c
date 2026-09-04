#include <stdint.h>

extern void RV32_Exit(int code);

#define UART_BASE 0x10000000U
#define UART_RBR  0x00U
#define UART_LSR  0x05U
#define UART_LSR_DR 0U
#define UART_LSR_THRE 5U

static volatile uint8_t* const uart_register(uint32_t offset){
    return (volatile uint8_t*)(UART_BASE + offset);
}
static void uart_putc(char value){
    volatile uint8_t* const lsr = uart_register(UART_LSR);
    while (((*lsr >> UART_LSR_THRE) & 1U) == 0U) {}
    *uart_register(UART_RBR) = (uint8_t)value;
}
static void uart_puts(const char* text){
    while(*text){
        uart_putc(*text++);
    }
}

static int uart_getc(void){
    volatile uint8_t* const lsr = uart_register(UART_LSR);
    if(((*lsr >> UART_LSR_DR) & 1U) == 0U){
        return -1;
    }
    return *uart_register(UART_RBR);
}
static void uart_getline(char* buffer,int max_length){
    int ch = -1;
    int i = 0;

    while(i < max_length - 1 && ch != '\n'){
        while ((ch = uart_getc()) == -1) {}
        if(ch == '\b'){
            if(i > 0) i--;
            continue;
        }
        buffer[i] = (char)ch;
        i++;
    }

    buffer[i] = '\0';
}

int main(void){
    uart_puts("Hello from RISC-V!\n");

    uint32_t a = 123;
    uint32_t b = 456;
    uint32_t c = a + b;

    if (c == 579)
        uart_puts("ADD: OK\n");
    else
        uart_puts("ADD: FAIL\n");

    char buffer[128];
    uart_puts("Enter a line: ");
    uart_getline(buffer, sizeof(buffer));

    uart_puts("\nReceived Buffer: \"");
    uart_puts(buffer);
    uart_puts("\"\n");
    return 0;
}
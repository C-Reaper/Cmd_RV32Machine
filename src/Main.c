#define RV32MACHINE_DEBUG

#if defined(__linux__)
#include "/home/codeleaded/System/Static/Library/RV32Machine.h"
#elif defined(_WINE)
#include "/home/codeleaded/System/Static/Library/RV32Machine.h"
#elif defined(_WIN32)
#include "F:/home/codeleaded/System/Static/Library/RV32Machine.h"
#elif defined(__APPLE__)
#error "Apple not supported!"
#else
#error "Platform not supported!"
#endif

int main(){
    RV32Machine rv = RV32Machine_New();
    //RV32Machine_Reset(&rv);
    RV32Machine_Load_From(&rv,"./bin/main.elf");
    RV32Machine_Print(&rv);
    RV32Memory_PrintSize(&rv.ram,RV32MACHINE_ADR_RAM,1024U);
    RV32Machine_Start(&rv);
    RV32Machine_Free(&rv);
    return 0;
}
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
    RV32Machine rv32 = RV32Machine_New();
    //RV32Machine_Load_From(&rv32,"./data/rom.rv32");
    RV32Machine_Print(&rv32);
    RV32Machine_Start(&rv32);
    RV32Machine_Free(&rv32);
    return 0;
}
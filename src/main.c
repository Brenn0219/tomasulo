#include <stdio.h>
#include "instruction.h"
#include "print.h"

int main() {
    char str[] = "MULT,X0,X1,X2";
    Instr instr;

    parse_instr(str, &instr);
    print_instr(&instr);

    return 0;
}
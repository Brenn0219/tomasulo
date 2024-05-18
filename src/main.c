#include <stdio.h>
#include "reorder_buffer.h"

int main() {
    char str[] = "MULT,X0,X1,X2";
    Instr instr;

    parse_instr(str, &instr);
    print_instr(&instr);

    return 0;
}
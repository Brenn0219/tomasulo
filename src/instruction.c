#include <string.h>
#include <stdlib.h>
#include "instruction.h"
#include "type.h"

static void parse_reg(Reg *reg, char *str) {
    if (!strcmp(str, "X0")) 
        *reg = X0;
    else if (!strcmp(str, "X1"))
        *reg = X1;
    else if (!strcmp(str, "X2"))
        *reg = X2;
    else if (!strcmp(str, "X3"))
        *reg = X3;
    else if (!strcmp(str, "X4"))
        *reg = X4;
    else if (!strcmp(str, "X5"))
        *reg = X5;
    else
        *reg = X6;
}

void parse_instr(char *str, Instr *istr) {
    char delimiter[] = ","; 

    char *parse = strtok(str, delimiter);

    if (!strcmp(parse, "MULT")) 
        istr->type = MULT;
    else if (!strcmp(parse, "ADD"))
        istr->type = ADD;
    else 
        istr->type = SUB;
    
    parse = strtok(NULL, delimiter);
    parse_reg(&istr->dest, parse);

    parse = strtok(NULL, delimiter);
    parse_reg(&istr->op1, parse);

    parse = strtok(NULL, delimiter);
    parse_reg(&istr->op2, parse);
}
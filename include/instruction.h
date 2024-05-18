#ifndef INTRUCTION_H
#define INTRUCTION_H

#include <stdlib.h>
#include <string.h>
#include "type.h"

typedef enum {
    ADD,
    SUB,
    MULT,
} InstrType;

typedef enum {
    X0,
    X1,
    X2,
    X3,
    X4,
    X5,
    X6
} Reg;

typedef union Instr {
    InstrType type;
    Reg dest;
    Reg op1;
    Reg op2;
} Instr;

void parse_instr(char *str, Instr *instr);



#endif
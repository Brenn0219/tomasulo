#ifndef INTRUCTION_H
#define INTRUCTION_H

#include "registrar.h"

typedef enum {
    ADD,
    SUB,
    MULT,
} InstrType;

typedef struct {
    InstrType type;
    Reg dest;
    Reg op1;
    Reg op2;
} Instr;

void instruction_init(Instr *i);
void instruction_parse(Instr *i, char *str);

#endif
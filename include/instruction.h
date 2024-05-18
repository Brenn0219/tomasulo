#ifndef INTRUCTION_H
#define INTRUCTION_H

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

typedef struct {
    InstrType type;
    Reg dest;
    Reg op1;
    Reg op2;
} Instr;

void parse_instr(char *str, Instr *instr);
void parse_reg(Reg *reg, char *str);

#endif
#include "instruction.h"

static void parse_reg(Reg reg, char *str) {
    if (!strcmp(str, "X0")) 
        reg = X0;
    else if (!strcmp(str, "X1"))
        reg = X1;
    else if (!strcmp(str, "X2"))
        reg = X2;
    else if (!strcmp(str, "X3"))
        reg = X3;
    else if (!strcmp(str, "X4"))
        reg = X4;
    else if (!strcmp(str, "X5"))
        reg = X5;
    else
        reg = X6;
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
    parse_reg(istr->dest, parse);

    parse = strtok(NULL, delimiter);
    parse_reg(istr->op1, parse);

    parse = strtok(NULL, delimiter);
    parse_reg(istr->op2, parse);

    free(parse);
}

static void print_reg(Reg reg) {
    switch (reg) {
        case X0:
            printf("X0 ");
            break;
        
        case X1:
            printf("X1 ");
            break;
    
        case X2:
            printf("X2 ");
            break;

        case X3:
            printf("X3 ");
            break;

        case X4:
            printf("X4 ");
            break;

        case X5:
            printf("X5 ");
            break;

        default:
            printf("X6 ");
            break;
    }
}

void print_instr(Instr *instr) {
    switch (instr->type) {
        case ADD:
            printf("type: ADD ");
            break;
        
        case SUB:
            printf("type: SUB ");
            break;
        
        default:
            printf("type: MULT ");
            break;
    }

    printf("dest: ");
    print_reg(instr->dest);

    printf("op1: ");
    print_reg(instr->op1);

    printf("op2: ");
    print_reg(instr->op2);

    printf("\n");
}
#include "print.h"

void print_reg(Reg reg) {
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
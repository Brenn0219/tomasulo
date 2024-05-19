#include <stdio.h>
#include "print.h"

void print_reg(Reg r) {
    switch (r.id) {
        case F0:
            printf("{F0, %d} ", r.value);
            break;
        
        case F1:
            printf("{F1, %d} ", r.value);
            break;
    
        case F2:
            printf("{F2, %d} ", r.value);
            break;

        case F3:
            printf("{F3, %d} ", r.value);
            break;

        case F4:
            printf("{F4, %d} ", r.value);
            break;

        case F5:
            printf("{F5, %d} ", r.value);
            break;

        default:
            printf("{F6, %d} ", r.value);
            break;
    }
}

void print_instruction(Instr *i) {
    switch (i->type) {
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
    print_reg(i->dest);

    printf("op1: ");
    print_reg(i->op1);

    printf("op2: ");
    print_reg(i->op2);

    printf("\n");
}

void print_status(Status stt) {
    printf("status: ");

    switch (stt) {
        case WAIT:
            printf("WAIT\n");
            break;
        
        case DISPATCH:
            printf("DISPATCH\n");
            break;

        case EXECUTION:
            printf("EXECUTION\n");
            break;

        case WRITEBACK:
            printf("WRITEBACK\n");
            break;
            
        default:
            printf("COMMIT\n");
            break;
    }
}

void print_buffer(Buffer *bff) {
    printf("id: %d busy: %s \n", bff->id, (bff->busy ? "true" : "false"));
    print_instruction(&bff->ist);
    print_status(bff->stt);
    printf("\n");
}
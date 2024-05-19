#include <string.h>
#include "instruction.h"

#include <stdio.h>

#define DELIMITER ","

static void reg_parse(Reg *reg, char *str) {
    if (!strcmp(str, "F0")) 
        reg->id = F0;
    else if (!strcmp(str, "F1"))
        reg->id = F1;
    else if (!strcmp(str, "F2"))
        reg->id = F2;
    else if (!strcmp(str, "F3"))
        reg->id = F3;
    else if (!strcmp(str, "F4"))
        reg->id = F4;
    else if (!strcmp(str, "F5"))
        reg->id = F5;
    else
        reg->id = F6;
}

static void instr_parse_type(Instr *i, char *token) {
    
    if (!strcmp(token, "MULT")) 
        i->type = MULT;
    else if (!strcmp(token, "ADD"))
        i->type = ADD;
    else 
        i->type = SUB;
}

void instruction_parse(Instr *i, char *str) {
    char *token = strtok(str, DELIMITER);
    instr_parse_type(i, token);
    
    token = strtok(NULL, DELIMITER);
    reg_parse(&i->dest, token);

    token = strtok(NULL, DELIMITER);
    reg_parse(&i->op1, token);

    token = strtok(NULL, DELIMITER);
    reg_parse(&i->op2, token);
}

void instruction_init(Instr *i) {
    reg_init(&i->dest);
    reg_init(&i->op1);
    reg_init(&i->op2);
}
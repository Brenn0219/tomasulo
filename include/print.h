#ifndef PRINT_H
#define PRINT_H

#pragma once

#include "reordering.h"

void print_instruction(Instr *i);
void print_reg(Reg r);
void print_status(Status stt);
void print_buffer(Buffer *bff);

#endif
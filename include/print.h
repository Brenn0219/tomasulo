#ifndef PRINT_H
#define PRINT_H

#pragma once

#include "reordering.h"

void print_instr(Instr *instr);
void print_reg(Reg reg);
void print_status(Status stt);
void print_buffer(Buffer *bff);

#endif
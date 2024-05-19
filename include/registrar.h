#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <stdint.h>

#define i64 int64_t

typedef enum {
    F0,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F_DEFAULT 
} RegId;

typedef struct {
    RegId id;
    i64 value;
} Reg;

void reg_init(Reg *r);

#endif
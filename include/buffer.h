#ifndef BUFFER_H
#define BUFFER_H

#include <stdbool.h> 
#include "instruction.h"

#define u8 uint8_t

typedef enum {
    WAIT,
    DISPATCH,
    EXECUTION,
    WRITEBACK,
    COMMIT
} Status;

typedef struct {
    u8 id;
    bool busy;
    Instr ist;
    Status stt;
    i64 value;
} Buffer;

#endif
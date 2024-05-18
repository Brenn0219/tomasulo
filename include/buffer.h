#ifndef BUFFER_H
#define BUFFER_H

#include "instruction.h"
#include "type.h"

typedef enum Status {
    WAIT,
    DISPATCH,
    EXECUTION,
    WRITEBACK,
    COMMIT
} Status;

typedef struct Buffer {
    u8 id;
    bool busy;
    Instr istr;
    Status stt;
} Buffer;

#endif
#ifndef REORDERING_H
#define REORDERING_H

#include <stdlib.h> 
#include <stdio.h>
#include "buffer.h"

#define TOTAL_BUFFER 7

void reobuf_add(Buffer *rb, FILE *file);

#endif
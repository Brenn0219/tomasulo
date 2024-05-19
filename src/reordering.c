#include <stdlib.h>
#include "reordering.h"

void reobuf_add(Buffer *rb, FILE *file) {
    int i = 0; 
    char str[15];

    while (fscanf(file, "%s", str) != EOF) 
        instruction_parse(&rb[i].ist, str);
}
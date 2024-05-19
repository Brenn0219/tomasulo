#include <stdio.h>
#include "reordering.h"
#include "print.h"

int main() {
    const char *path = "data/in.txt";
    FILE *file = fopen(path, "r");
    Buffer *rb = (Buffer *) malloc(sizeof(Buffer) * TOTAL_BUFFER);

    if (file == NULL) {
        perror("error\n");
        return -1;
    }

    reobuf_add(rb, file);

    return 0;
}
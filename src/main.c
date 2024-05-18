#include <stdio.h>
#include <stdlib.h>
#include "reordering.h"
#include "print.h"

#define INPUT_SIZE 15

int main() {
    const char *path = "data/in.txt";
    FILE *file = fopen(path, "r");
    char str[INPUT_SIZE]; 

    if (file == NULL) {
        perror("error\n");
        return -1;
    }

    Instr instr;

    while (fscanf(file, "%s", str) != EOF) {
       parse_instr(str, &instr);
       print_instr(&instr);
    }

    return 0;
}
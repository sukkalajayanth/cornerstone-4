#include <stdio.h>
#include <string.h>

enum {
    HALT,
    PUSH,
    POP,
    ADD,
    SUB,
    MUL,
    DIV,
    LOAD,
    STORE,
    JMP,
    JZ
};

typedef struct {
    char name[32];
    int address;
} Label;

Label labels[50];
int label_count = 0;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: assembler <file.asm>\n");
        return 1;
    }

    printf("Assembling %s\n", argv[1]);
    return 0;
}

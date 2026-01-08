#ifndef VM_H
#define VM_H

#define STACK_SIZE 256
#define MEM_SIZE 1024

// Opcode definitions (shared)
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
    int stack[STACK_SIZE];
    int sp;
    int pc;
    int memory[MEM_SIZE];
    int *code;
    int code_size;
} VM;

void init_vm(VM *vm, int *code, int size);
void run_vm(VM *vm);

#endif

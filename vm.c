#include "vm.h"
#include <stdio.h>

enum {
    HALT,
    PUSH,
    POP,
    ADD,
    SUB,
    MUL,
    DIV
};

void run_vm(VM *vm) {
    while (vm->pc < vm->code_size) {
        int opcode = vm->code[vm->pc++];

        switch (opcode) {
            case PUSH:
                vm->stack[++vm->sp] = vm->code[vm->pc++];
                break;

            case POP:
                vm->sp--;
                break;

            case ADD:
                vm->stack[vm->sp - 1] += vm->stack[vm->sp];
                vm->sp--;
                break;

            case SUB:
                vm->stack[vm->sp - 1] -= vm->stack[vm->sp];
                vm->sp--;
                break;

            case MUL:
                vm->stack[vm->sp - 1] *= vm->stack[vm->sp];
                vm->sp--;
                break;

            case DIV:
                vm->stack[vm->sp - 1] /= vm->stack[vm->sp];
                vm->sp--;
                break;

            case HALT:
                return;
        }
    }
}

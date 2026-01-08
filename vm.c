#include "vm.h"
#include <stdio.h>

void init_vm(VM *vm, int *code, int size) {
    vm->sp = -1;
    vm->pc = 0;
    vm->code = code;
    vm->code_size = size;

    for (int i = 0; i < MEM_SIZE; i++)
        vm->memory[i] = 0;
}

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

            case LOAD:
                vm->stack[++vm->sp] = vm->memory[vm->code[vm->pc++]];
                break;

            case STORE:
                vm->memory[vm->code[vm->pc++]] = vm->stack[vm->sp--];
                break;

            case JMP:
                vm->pc = vm->code[vm->pc];
                break;

            case JZ:
                if (vm->stack[vm->sp--] == 0)
                    vm->pc = vm->code[vm->pc];
                else
                    vm->pc++;
                break;

            case HALT:
                return;
        }
    }
}

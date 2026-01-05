#include "vm.h"

void init_vm(VM *vm, int *code, int size) {
    vm->sp = -1;
    vm->pc = 0;
    vm->code = code;
    vm->code_size = size;

    for (int i = 0; i < MEM_SIZE; i++) {
        vm->memory[i] = 0;
    }
}

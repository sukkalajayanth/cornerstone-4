#include "vm.h"
#include <stdio.h>

int main() {
    int code[] = {
        PUSH, 10,
        PUSH, 20,
        ADD,
        HALT
    };

    VM vm;
    init_vm(&vm, code, sizeof(code) / sizeof(int));
    run_vm(&vm);

    printf("Result: %d\n", vm.stack[vm.sp]);
    return 0;
}

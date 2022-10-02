#include <stdio.h>
#include <stdint.h>
#include "stack.h"
#include "interpret.h"
#include "stek_vm.h"

const union ins program[] = {
        { BC_IREAD },
        { BC_IREAD },
        { BC_DUP },
        { .as_arg64 = { BC_PUSH, .arg = 10 } },
        { BC_IMUL },
        { BC_IADD },
        { BC_IADD },
        { BC_IPRINT },
        { BC_STOP }
};

int main() {
    struct vm_state state = {.ip = program, .data_stack = stack_create(10)};
    interpret(&state);
    stack_print(&state.data_stack);
    state_destroy(&state);
    return 0;
}

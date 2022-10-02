#ifndef C_COURSE_STEK_VM_H
#define C_COURSE_STEK_VM_H
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include "stack.h"
#include "interpret.h"
enum opcode {
    BC_PUSH, BC_POP, BC_SWAP, BC_DUP,
    BC_IADD, BC_ISUB, BC_IMUL, BC_IDIV, BC_IMOD,
    BC_INEG,
    BC_IPRINT, BC_IREAD,
    BC_ICMP,
    BC_JMP, BC_JZ,
    BC_STOP
};

enum ins_arg_type { IAT_NOARG, IAT_I64 };

struct ins_descr {
    const char* mnemonic;
    enum ins_arg_type argtype;
    bool affects_ip;
    size_t stack_min;
    int64_t stack_delta;
};

struct bc_noarg {
    enum opcode opcode;
};
struct bc_arg64 {
    enum opcode opcode;
    int64_t arg;
};

union ins {
    enum opcode opcode;
    struct bc_arg64 as_arg64;
    struct bc_noarg as_noarg;
};

struct vm_state {
    const union ins *ip;
    struct stack data_stack;
};
typedef void (*stack_command)(struct vm_state *state);



void state_destroy(struct vm_state *state);
void interpret_with_actions(struct vm_state* state, const stack_command actions[]);
void interpret(struct vm_state* state);

#endif //C_COURSE_STEK_VM_H

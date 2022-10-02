#include "stek_vm.h"

void state_destroy(struct vm_state *state) {
    stack_destroy(&state->data_stack);
}

static const stack_command interpreters[] = {
        [BC_PUSH] = (stack_command) interpret_push,
        [BC_POP] = (stack_command) interpret_pop,
        [BC_SWAP] = (stack_command) interpret_swap,
        [BC_DUP] = (stack_command) interpret_dup,
        [BC_IADD] = (stack_command) interpret_iadd,
        [BC_ISUB] = (stack_command) interpret_isub,
        [BC_IMUL] = (stack_command) interpret_imul,
        [BC_IDIV] = (stack_command) interpret_idiv,
        [BC_INEG] = (stack_command) interpret_ineg,
        [BC_IPRINT] = (stack_command) interpret_iprint,
        [BC_IREAD] = (stack_command) interpret_iread,
        [BC_ICMP] = (stack_command) interpret_icmp,
        [BC_STOP] = (stack_command) interpret_stop
};

static const struct ins_descr instructions[] = {
        /*             mnemonic  argtype    affects_ip */
        [BC_PUSH]   = {"push",IAT_I64  ,  false, 0, 1},
        [BC_IADD]   = {"iadd",  IAT_NOARG,false, 2, -1},
        [BC_ISUB]   = {"isub",  IAT_NOARG,false, 2, -1},
        [BC_IMUL]   = {"imul",  IAT_NOARG,false, 2, -1},
        [BC_IDIV]   = {"idiv",  IAT_NOARG,false, 2, -1},
        [BC_IMOD]   = {"imod",  IAT_NOARG,false, 2, -1},
        [BC_INEG]   = {"ineg",  IAT_NOARG,false, 1, 0},
        [BC_IPRINT] = {"iprint",IAT_NOARG,false, 1, -1},
        [BC_IREAD]  = {"iread", IAT_NOARG,false, 0, 1},
        [BC_SWAP]   = {"swap",  IAT_NOARG,false, 2, 0},
        [BC_POP]    = {"pop",   IAT_NOARG,false, 1, -1},
        [BC_DUP]    = {"dup",   IAT_NOARG,false, 1, 2},
        [BC_ICMP]   = {"icmp",  IAT_NOARG,false, 2, -1},
        [BC_JMP]    = {"jmp",   IAT_I64  ,true},
        [BC_JZ]     = {"jz",    IAT_I64  ,true},
        [BC_STOP]   = {"stop",  IAT_NOARG,true}
};

void interpret_with_actions(struct vm_state* state, const stack_command actions[]) {
    for (; state->ip ;) {
        const union ins* ins = state->ip;
        const struct ins_descr* ins_descr = instructions + ins->opcode;
        int64_t dif = (ins_descr->stack_delta) + (int64_t)(state->data_stack.count);

        if (ins_descr->stack_min > state->data_stack.count || dif < 0){
            printf("Stack underflow\n");
            return;
        }
        if (dif > state->data_stack.data.size){
            printf("Stack overflow\n");
            return;
        }
        actions[ins->opcode](state);
        if (!ins_descr->affects_ip) { state->ip = state->ip + 1; }
    }
}

void interpret(struct vm_state *state) {
    interpret_with_actions(state, interpreters);
}

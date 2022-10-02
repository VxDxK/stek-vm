#include "interpret.h"

void interpret_swap ( struct vm_state* state ) {
    int64_t a = stack_pop(&state->data_stack).value;
    int64_t b = stack_pop(&state->data_stack).value;
    stack_push(&state->data_stack, a);
    stack_push(&state->data_stack, b);
}
void interpret_pop(struct vm_state* state) {
    stack_pop(&state->data_stack);
}

void interpret_dup(struct vm_state* state) {
    int64_t a = stack_pop(&state->data_stack).value;
    stack_push(&state->data_stack, a);
    stack_push(&state->data_stack, a);
}

void lift_unop( struct stack* s, int64_t (f)(int64_t)){
    int64_t a = stack_pop(s).value;
    int64_t ans = f(a);
    stack_push(s, ans);
}

void lift_binop( struct stack* s, int64_t (f)(int64_t, int64_t)){
    int64_t a = stack_pop(s).value;
    int64_t b = stack_pop(s).value;
    int64_t ans = f(b, a);
    stack_push(s, ans);
}

int64_t i64_add(int64_t a, int64_t b) { return a + b; }
int64_t i64_sub(int64_t a, int64_t b) { return a - b; }
int64_t i64_mul(int64_t a, int64_t b) { return a * b; }
int64_t i64_div(int64_t a, int64_t b) { return a / b; }
int64_t i64_cmp(int64_t a, int64_t b) { if (a > b) return 1; else if (a < b) return -1; return 0; }

int64_t i64_neg(int64_t a) { return -a; }

void interpret_iadd( struct vm_state* state ) {
    lift_binop(& state->data_stack, i64_add);
}
void interpret_isub( struct vm_state* state ) {
    lift_binop(& state->data_stack, i64_sub);
}
void interpret_imul( struct vm_state* state ) {
    lift_binop(& state->data_stack, i64_mul);
}
void interpret_idiv( struct vm_state* state ) {
    lift_binop(& state->data_stack, i64_div);
}
void interpret_icmp( struct vm_state* state ) {
    lift_binop(& state->data_stack, i64_cmp);
}

void interpret_ineg( struct vm_state* state ) {
    lift_unop (&state->data_stack, i64_neg);
}

void interpret_push(struct vm_state* state) {
    stack_push(&state->data_stack, state->ip->as_arg64.arg);
}

void interpret_iread(struct vm_state* state ) {
    int64_t val = read_int64();
    stack_push(&state->data_stack, val);
}

void interpret_iprint(struct vm_state* state ) {
    int64_t val = stack_pop(&state->data_stack).value;
    print_int64(val);
}

void interpret_stop(struct vm_state* state ) {
    state->ip = NULL;
}


#ifndef C_COURSE_INTERPRET_H
#define C_COURSE_INTERPRET_H
#include "inttypes.h"
#include "stdbool.h"
#include "stack.h"
#include "stek_vm.h"
void interpret_swap ( struct vm_state* state );
void interpret_pop(struct vm_state* state);
void interpret_dup(struct vm_state* state);
void lift_unop( struct stack* s, int64_t (f)(int64_t));
void lift_binop( struct stack* s, int64_t (f)(int64_t, int64_t));

int64_t i64_add(int64_t a, int64_t b);
int64_t i64_sub(int64_t a, int64_t b);
int64_t i64_mul(int64_t a, int64_t b);
int64_t i64_div(int64_t a, int64_t b);
int64_t i64_cmp(int64_t a, int64_t b);

int64_t i64_neg(int64_t a);

void interpret_iadd( struct vm_state* state );
void interpret_isub( struct vm_state* state );
void interpret_imul( struct vm_state* state );
void interpret_idiv( struct vm_state* state );
void interpret_icmp( struct vm_state* state );
void interpret_ineg( struct vm_state* state );
void interpret_push(struct vm_state* state);
void interpret_iread(struct vm_state* state );
void interpret_iprint(struct vm_state* state );
void interpret_stop(struct vm_state* state );

#endif //C_COURSE_INTERPRET_H

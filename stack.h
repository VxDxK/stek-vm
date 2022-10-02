#ifndef C_COURSE_STACK_H
#define C_COURSE_STACK_H
#include "array_int.h"
#include "util.h"
struct stack {
    size_t count;
    struct array_int data;
};

struct stack stack_create( size_t size );
size_t stack_count( const struct stack* s );
void stack_destroy( struct stack* s );
bool stack_is_full( const struct stack * s);
bool stack_is_empty( const struct stack * s);
bool stack_push( struct stack* s, int64_t value );
struct maybe_int64 stack_pop( struct stack* s );
void stack_print( const struct stack* s );
#endif //C_COURSE_STACK_H

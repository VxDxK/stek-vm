#include "stack.h"

struct stack stack_create( size_t size ){
    return (struct stack){.data = array_int_create(size), .count=0 };
};

size_t stack_count( const struct stack* s ){
    return s->count;
};


void stack_destroy( struct stack* s ){
    free(s->data.data);
};

bool stack_is_full( const struct stack * s){
    if (s -> count >= s -> data.size){
        return true;
    }
    return false;
};
bool stack_is_empty( const struct stack * s){
    if (s -> count == 0){
        return true;
    }
    return false;
};

bool stack_push( struct stack* s, int64_t value ){
    if (!stack_is_full(s)){
        s -> count++;
        return array_int_set(s -> data,s -> count - 1    , value);
    }
    return false;
};

struct maybe_int64 stack_pop( struct stack* s ){
    if(stack_is_empty(s)) return none_maybe();
    s->count--;
    return array_int_get(s->data,s->count);
};

void stack_print( const struct stack* s ) {
    for (size_t i = 0; i < stack_count( s ); i = i + 1 ) {
        print_int64( array_int_get( s->data, i).value );
        printf(" ");
    }
}
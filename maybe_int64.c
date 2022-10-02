#include "maybe_int64.h"
struct maybe_int64 some_int64( int64_t i ) {
    return (struct maybe_int64) { .value = i, .valid = true };
}

struct maybe_int64 none_maybe(){
    return (struct maybe_int64){.valid = 0, .value = 0};
}
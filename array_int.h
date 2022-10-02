#ifndef C_COURSE_ARRAY_INT_H
#define C_COURSE_ARRAY_INT_H
#include <stdint.h>
#include <malloc.h>
#include <stdbool.h>
#include <inttypes.h>
#include "maybe_int64.h"
#include "util.h"
struct array_int {
    int64_t *data;
    size_t size;
};

void array_int_fill( int64_t* array, size_t sz );
struct array_int array_int_read();
void array_int_print( struct array_int array );
void array_int_free( struct array_int a );
struct maybe_int64 array_int_min( struct array_int array );
struct maybe_int64 array_int_get( struct array_int a, size_t i );
bool array_int_set( struct array_int a, size_t i, int64_t value );
struct array_int array_int_create( size_t sz );

#endif //C_COURSE_ARRAY_INT_H

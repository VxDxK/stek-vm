#ifndef C_COURSE_MAYBE_INT64_H
#define C_COURSE_MAYBE_INT64_H
#include <stdbool.h>
#include <inttypes.h>
struct maybe_int64 {
    bool valid;
    int64_t value;
};
struct maybe_int64 some_int64( int64_t i );

static const struct maybe_int64 none_int64a = { 0 };
struct maybe_int64 none_maybe();

#endif //C_COURSE_MAYBE_INT64_H

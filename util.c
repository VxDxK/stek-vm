#include "util.h"

int64_t read_int64() {
    int64_t t;
    scanf("%"SCNd64, &t);
    return t;
}

size_t read_size() {
    size_t t;
    scanf("%zu", &t);
    return t;
}

void print_int64(int64_t val) {
    printf("%"PRId64, val);
}

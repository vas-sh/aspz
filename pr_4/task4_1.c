#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int main(void) {
    printf("sizeof(size_t) = %zu bytes\n", sizeof(size_t));
    printf("SIZE_MAX = %zu\n", (size_t)SIZE_MAX);

    void *ptr = malloc(SIZE_MAX);

    if (ptr == NULL) {
        printf("malloc(SIZE_MAX) failed\n");
    } else {
        printf("malloc(SIZE_MAX) success\n");
        free(ptr);
    }

    return 0;
}
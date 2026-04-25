#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    int *ptr = malloc(10 * sizeof(int));

    if (!ptr) {
        printf("initial malloc failed\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        ptr[i] = i;
    }

    int *newptr = realloc(ptr, SIZE_MAX);

    if (!newptr) {
        printf("realloc failed, old pointer is still valid\n");
        printf("ptr[0] = %d\n", ptr[0]);
        free(ptr);
        return 1;
    }

    ptr = newptr;
    free(ptr);

    return 0;
}
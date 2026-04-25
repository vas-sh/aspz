#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *a = realloc(NULL, 10 * sizeof(int));

    if (a) {
        printf("realloc(NULL, size) works like malloc\n");
    }

    void *b = realloc(a, 0);

    if (b == NULL) {
        printf("realloc(ptr, 0) returned NULL\n");
    } else {
        printf("realloc(ptr, 0) returned pointer: %p\n", b);
        free(b);
    }

    return 0;
}
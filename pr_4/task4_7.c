#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

struct sbar {
    int id;
    double value;
};

int main(void) {
    struct sbar *ptr = calloc(1000, sizeof(struct sbar));

    if (!ptr) {
        printf("calloc failed\n");
        return 1;
    }

    struct sbar *newptr = reallocarray(ptr, 500, sizeof(struct sbar));

    if (!newptr) {
        printf("reallocarray failed\n");
        free(ptr);
        return 1;
    }

    ptr = newptr;

    printf("reallocarray success\n");

    free(ptr);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *ptr = NULL;

    for (int i = 0; i < 3; i++) {
        if (!ptr) {
            ptr = malloc(32);
            if (!ptr) {
                printf("malloc failed\n");
                return 1;
            }
        }

        strcpy(ptr, "Hello");
        printf("Iteration %d: %s\n", i, ptr);

        free(ptr);
        ptr = NULL;
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int i = 0;

    while (1) {
        void *ptr = malloc(1024 * 1024);

        if (ptr == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        ((char*)ptr)[0] = 'A';

        printf("Iteration: %d, allocated 1MB\n", i++);
        sleep(1);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        printf("%f\n", (float)rand() / RAND_MAX);
    }
}
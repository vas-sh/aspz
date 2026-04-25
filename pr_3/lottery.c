#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    while (1) {
        for (int i = 0; i < 7; i++)
            printf("%d ", rand() % 49 + 1);

        printf("\n");
    }
}
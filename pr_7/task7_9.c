#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();

    for (int i = 0; i < 100000000; i++);

    clock_t end = clock();

    printf("Time: %f ms\n",
           (double)(end - start) * 1000 / CLOCKS_PER_SEC);
}
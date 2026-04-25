#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000
#define REPEAT 20
#define ALIGNMENT 64

static double now_seconds(void) {
    return (double)clock() / CLOCKS_PER_SEC;
}

static double test_array(double *arr) {
    double sum = 0.0;

    for (int r = 0; r < REPEAT; r++) {
        for (size_t i = 0; i < N; i++) {
            arr[i] = (double)i * 0.5;
        }

        for (size_t i = 0; i < N; i++) {
            sum += arr[i];
        }
    }

    return sum;
}

int main(void) {
    size_t size = N * sizeof(double);

    double *malloc_arr = malloc(size);

    if (!malloc_arr) {
        printf("malloc failed\n");
        return 1;
    }

    double start = now_seconds();
    double malloc_sum = test_array(malloc_arr);
    double malloc_time = now_seconds() - start;

    free(malloc_arr);

    double *aligned_arr = aligned_alloc(ALIGNMENT, size);

    if (!aligned_arr) {
        printf("aligned_alloc failed\n");
        return 1;
    }

    start = now_seconds();
    double aligned_sum = test_array(aligned_arr);
    double aligned_time = now_seconds() - start;

    free(aligned_arr);

    printf("malloc sum: %.2f\n", malloc_sum);
    printf("malloc time: %.6f seconds\n", malloc_time);

    printf("aligned_alloc sum: %.2f\n", aligned_sum);
    printf("aligned_alloc time: %.6f seconds\n", aligned_time);

    return 0;
}
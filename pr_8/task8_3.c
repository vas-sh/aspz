#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 100000

int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

double now_seconds(void) {
    return (double)clock() / CLOCKS_PER_SEC;
}

void fill_sorted(int *arr) {
    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }
}

void fill_reversed(int *arr) {
    for (int i = 0; i < N; i++) {
        arr[i] = N - i;
    }
}

void fill_random(int *arr) {
    for (int i = 0; i < N; i++) {
        arr[i] = rand();
    }
}

void fill_same(int *arr) {
    for (int i = 0; i < N; i++) {
        arr[i] = 7;
    }
}

int is_sorted(int *arr) {
    for (int i = 1; i < N; i++) {
        if (arr[i - 1] > arr[i]) {
            return 0;
        }
    }

    return 1;
}

void test_case(const char *name, void (*fill)(int *)) {
    int *arr = malloc(N * sizeof(int));

    if (!arr) {
        printf("malloc failed\n");
        return;
    }

    fill(arr);

    double start = now_seconds();
    qsort(arr, N, sizeof(int), cmp_int);
    double end = now_seconds();

    printf("%-15s time: %.6f sec, sorted: %s\n",
           name,
           end - start,
           is_sorted(arr) ? "yes" : "no");

    free(arr);
}

int main(void) {
    srand(time(NULL));

    test_case("sorted", fill_sorted);
    test_case("reversed", fill_reversed);
    test_case("random", fill_random);
    test_case("same values", fill_same);

    return 0;
}
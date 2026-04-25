#include <stdio.h>
#include <string.h>

#include "insort.h"

typedef struct {
    char keyword[32];
    int frequency;
} Record;

static int cmp_int_asc(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

static int cmp_record_multi(const void *a, const void *b) {
    const Record *ra = (const Record *)a;
    const Record *rb = (const Record *)b;

    int by_keyword = strcmp(ra->keyword, rb->keyword);
    if (by_keyword != 0) {
        return by_keyword;
    }

    if (ra->frequency > rb->frequency) return -1;
    if (ra->frequency < rb->frequency) return 1;
    return 0;
}

static void print_int_array(const int *arr, size_t n, const char *title) {
    printf("%s\n", title);
    for (size_t i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

static void print_records(const Record *arr, size_t n, const char *title) {
    printf("%s\n", title);
    for (size_t i = 0; i < n; ++i) {
        printf("%-10s | %d\n", arr[i].keyword, arr[i].frequency);
    }
    printf("\n");
}

int main(void) {
    int numbers1[] = {23, 5, 17, 9, 1, 42, 17, 8};
    int numbers2[] = {23, 5, 17, 9, 1, 42, 17, 8};

    Record records[] = {
        {"banana", 5},
        {"apple", 2},
        {"banana", 9},
        {"cherry", 1},
        {"apple", 7}
    };

    size_t numbers_count = sizeof(numbers1) / sizeof(numbers1[0]);
    size_t records_count = sizeof(records) / sizeof(records[0]);

    print_int_array(numbers1, numbers_count, "Original integer array:");
    insort(numbers1, numbers_count, sizeof(int), cmp_int_asc);
    print_int_array(numbers1, numbers_count, "After insertion sort:");

    bin_insort(numbers2, numbers_count, sizeof(int), cmp_int_asc);
    print_int_array(numbers2, numbers_count, "After binary insertion sort:");

    print_records(records, records_count, "Original records:");
    insort(records, records_count, sizeof(Record), cmp_record_multi);
    print_records(records, records_count,
                  "Sorted records (keyword + frequency):");

    return 0;
}
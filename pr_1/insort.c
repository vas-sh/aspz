#include "insort.h"

#include <stdlib.h>
#include <string.h>

void insort(void *base, size_t n, size_t size,
            int (*cmp)(const void *, const void *)) {
    unsigned char *arr = (unsigned char *)base;
    unsigned char *temp;

    if (base == NULL || cmp == NULL || size == 0 || n < 2) {
        return;
    }

    temp = (unsigned char *)malloc(size);
    if (temp == NULL) {
        return;
    }

    for (size_t i = 1; i < n; ++i) {
        memcpy(temp, arr + i * size, size);

        size_t j = i;
        while (j > 0 && cmp(arr + (j - 1) * size, temp) > 0) {
            memmove(arr + j * size, arr + (j - 1) * size, size);
            --j;
        }

        memcpy(arr + j * size, temp, size);
    }

    free(temp);
}

void bin_insort(void *base, size_t n, size_t size,
                int (*cmp)(const void *, const void *)) {
    unsigned char *arr = (unsigned char *)base;
    unsigned char *temp;

    if (base == NULL || cmp == NULL || size == 0 || n < 2) {
        return;
    }

    temp = (unsigned char *)malloc(size);
    if (temp == NULL) {
        return;
    }

    for (size_t i = 1; i < n; ++i) {
        memcpy(temp, arr + i * size, size);

        size_t left = 0;
        size_t right = i;

        while (left < right) {
            size_t mid = left + (right - left) / 2;

            if (cmp(arr + mid * size, temp) <= 0) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        if (left < i) {
            memmove(arr + (left + 1) * size,
                    arr + left * size,
                    (i - left) * size);
            memcpy(arr + left * size, temp, size);
        }
    }

    free(temp);
}
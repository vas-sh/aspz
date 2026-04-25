#ifndef INSORT_H
#define INSORT_H

#include <stddef.h>

void insort(void *base, size_t n, size_t size,
            int (*cmp)(const void *, const void *));

void bin_insort(void *base, size_t n, size_t size,
                int (*cmp)(const void *, const void *));

#endif
#include <stdio.h>

void recurse(int depth) {
    int buffer[1000];

    buffer[0] = depth;

    printf("Depth: %d, stack address: %p\n", depth, (void *)&buffer);

    recurse(depth + 1);
}

int main(void) {
    recurse(1);
    return 0;
}
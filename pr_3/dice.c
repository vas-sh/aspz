#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *f = fopen("dice.txt", "w");
    if (!f) return 1;

    srand(time(NULL));

    while (1) {
        int roll = rand() % 6 + 1;
        fprintf(f, "%d\n", roll);
        fflush(f);
    }

    return 0;
}
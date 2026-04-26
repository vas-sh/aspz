#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s word file.txt\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[2], "r");
    if (f == NULL) {
        printf("Cannot open file %s\n", argv[2]);
        return 1;
    }

    char line[256];

    while (fgets(line, sizeof(line), f)) {
        if (strstr(line, argv[1])) {
            printf("%s", line);
        }
    }

    fclose(f);
    return 0;
}
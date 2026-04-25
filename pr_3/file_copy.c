#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Program need two arguments\n");
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        printf("Cannot open file %s for reading\n", argv[1]);
        return 1;
    }

    FILE *out = fopen(argv[2], "w");
    if (!out) {
        printf("Cannot open file %s for writing\n", argv[2]);
        return 1;
    }

    char c;
    while ((c = fgetc(in)) != EOF) {
        fputc(c, out);
    }

    fclose(in);
    fclose(out);
    return 0;
}
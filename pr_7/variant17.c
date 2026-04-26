#include <stdio.h>
#include <sys/stat.h>

void check(const char *path) {
    struct stat st;

    if (stat(path, &st) == 0) {
        printf("Checking %s\n", path);

        if (!(st.st_mode & S_IRUSR))
            printf("No read permission\n");

        if (!(st.st_mode & S_IWUSR))
            printf("No write permission\n");

        if (!(st.st_mode & S_IXUSR))
            printf("No execute permission\n");
    }
}

int main() {
    check("/etc/passwd");
    check("/etc/shadow");
    check("/home");

    printf("Paranoid config = minimal permissions\n");

    return 0;
}
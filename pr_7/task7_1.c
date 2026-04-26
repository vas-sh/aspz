#include <stdio.h>

int main() {
    FILE *fp = popen("ls -l | more", "r");
    if (!fp) {
        perror("popen");
        return 1;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }

    pclose(fp);
    return 0;
}
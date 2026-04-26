#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fp = popen("getent passwd", "r");

    if (fp == NULL) {
        perror("popen");
        return 1;
    }

    char line[512];

    printf("Regular users with UID >= 1000:\n");

    while (fgets(line, sizeof(line), fp)) {
        char copy[512];
        strcpy(copy, line);

        char *username = strtok(copy, ":");
        strtok(NULL, ":");
        char *uid_str = strtok(NULL, ":");

        if (username != NULL && uid_str != NULL) {
            int uid = atoi(uid_str);

            if (uid >= 1000 && uid < 65534) {
                printf("User: %-20s UID: %d\n", username, uid);
            }
        }
    }

    pclose(fp);
    return 0;
}
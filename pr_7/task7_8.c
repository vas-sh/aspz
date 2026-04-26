#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    DIR *dir = opendir(".");
    struct dirent *entry;

    while ((entry = readdir(dir))) {
        if (strstr(entry->d_name, ".c")) {
            printf("File: %s allow read? (y/n): ", entry->d_name);
            char c = getchar();
            getchar();

            if (c == 'y') {
                chmod(entry->d_name, 0644);
            }
        }
    }
}
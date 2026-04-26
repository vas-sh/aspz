#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    DIR *dir = opendir(".");
    struct dirent *entry;

    while ((entry = readdir(dir))) {
        struct stat st;
        stat(entry->d_name, &st);

        if (S_ISDIR(st.st_mode)) {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

void list(const char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;

    while ((entry = readdir(dir))) {
        if (entry->d_name[0] == '.') continue;

        char full[256];
        sprintf(full, "%s/%s", path, entry->d_name);

        printf("%s\n", full);

        struct stat st;
        stat(full, &st);

        if (S_ISDIR(st.st_mode)) {
            list(full);
        }
    }
    closedir(dir);
}

int main() {
    list(".");
}
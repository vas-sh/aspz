#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/ipc.h>

void print_permissions(mode_t mode) {
    printf((S_ISDIR(mode)) ? "d" : "-");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
}

int main() {
    DIR *dir = opendir(".");
    struct dirent *entry;
    struct stat st;

    while ((entry = readdir(dir))) {
        stat(entry->d_name, &st);
        print_permissions(st.st_mode);
        printf(" %s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
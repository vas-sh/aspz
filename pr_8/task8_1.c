#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(void) {
    int fd = open("task8_1_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buffer[] = "Hello UNIX write example\n";

    ssize_t count = write(fd, buffer, strlen(buffer));

    if (count == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Requested bytes: %zu\n", strlen(buffer));
    printf("Written bytes: %zd\n", count);

    close(fd);
    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(void) {
    int fd = 3;

    printf("Child after exec started\n");

    if (fcntl(fd, F_GETFD) != -1) {
        printf("File descriptor %d is still open after exec\n", fd);
        write(fd, "child wrote after exec\n", 23);
    } else {
        printf("File descriptor %d is closed after exec\n", fd);
        perror("fcntl");
    }

    return 0;
}
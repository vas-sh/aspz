#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void) {
    int fd = open("variant17_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("Parent opened file with fd = %d\n", fd);

    write(fd, "parent wrote before fork\n", 25);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        close(fd);
        return 1;
    }

    if (pid == 0) {
        execl("./variant17_child", "variant17_child", NULL);
        perror("execl");
        return 1;
    }

    wait(NULL);

    write(fd, "parent wrote after child\n", 25);

    close(fd);

    printf("Check file: cat variant17_output.txt\n");

    return 0;
}
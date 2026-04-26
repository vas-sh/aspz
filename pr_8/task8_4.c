#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    printf("pid = %d\n", pid);

    if (pid > 0) {
        wait(NULL);
    }

    return 0;
}
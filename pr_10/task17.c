#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child process started. PID = %d\n", getpid());

        sleep(5);

        printf("Child process finished.\n");
        exit(0);
    } else {
        int status;

        while (1) {
            pid_t result = waitpid(pid, &status, WNOHANG);

            if (result == 0) {
                printf("Parent: child is still running...\n");
            } else if (result == pid) {
                printf("Parent: child finished.\n");

                if (WIFEXITED(status)) {
                    printf("Exit code: %d\n", WEXITSTATUS(status));
                }

                break;
            } else {
                perror("waitpid failed");
                break;
            }

            sleep(1);
        }
    }

    return 0;
}
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void signal_handler(int sig) {
    printf("Child [%d]: caught signal %d\n", getpid(), sig);
    printf("Handler worked only once because of SA_RESETHAND\n");
}

void run_child() {
    struct sigaction sa;

    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);

    sa.sa_flags = SA_RESETHAND;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("Child started. PID = %d\n", getpid());
    printf("Send signal using:\n");
    printf("kill -USR1 %d\n", getpid());

    while (1) {
        pause();
    }
}

int main() {
    while (1) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            return 1;
        }

        if (pid == 0) {
            run_child();
            exit(0);
        }

        int status;

        waitpid(pid, &status, 0);

        printf("\nParent: child %d terminated.\n", pid);
        printf("Parent: creating new child with new one-time handler...\n\n");

        sleep(1);
    }

    return 0;
}
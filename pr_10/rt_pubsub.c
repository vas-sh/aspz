#define _POSIX_C_SOURCE 200809L

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int app_signal(void) {
    return SIGRTMIN;
}

static void subscriber(void) {
    int sig = app_signal();

    sigset_t set;

    sigemptyset(&set);
    sigaddset(&set, sig);

    sigprocmask(SIG_BLOCK, &set, NULL);

    printf("subscriber PID=%ld\n", (long)getpid());

    for (;;) {
        siginfo_t si;

        int r = sigwaitinfo(&set, &si);

        if (r == -1) {
            perror("sigwaitinfo");
            exit(EXIT_FAILURE);
        }

        int value = si.si_value.sival_int;

        printf("received value=%d from pid=%ld\n",
               value,
               (long)si.si_pid);

        if (value < 0) {
            break;
        }
    }
}

static void publisher(pid_t pid, int argc, char **argv) {
    int sig = app_signal();

    for (int i = 3; i < argc; i++) {
        union sigval value;

        value.sival_int = atoi(argv[i]);

        sigqueue(pid, sig, value);

        printf("sent value=%d\n", value.sival_int);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }

    if (strcmp(argv[1], "sub") == 0) {
        subscriber();
    } else if (strcmp(argv[1], "pub") == 0) {
        pid_t pid = (pid_t)atoi(argv[2]);

        publisher(pid, argc, argv);
    }

    return 0;
}
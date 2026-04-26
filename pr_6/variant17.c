#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>
#include <errno.h>

int main(void) {
    const char *msg1 = "Message printed with libc write()\n";
    const char *msg2 = "Message printed with direct syscall()\n";

    ssize_t result1 = write(STDOUT_FILENO, msg1, strlen(msg1));

    if (result1 == -1) {
        perror("write failed");
        return 1;
    }

    long result2 = syscall(SYS_write, STDOUT_FILENO, msg2, strlen(msg2));

    if (result2 == -1) {
        perror("syscall failed");
        return 1;
    }

    printf("\nComparison:\n");
    printf("write() result   = %zd bytes\n", result1);
    printf("syscall() result = %ld bytes\n", result2);

    return 0;
}
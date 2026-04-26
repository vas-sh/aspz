#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Home directory files:\n");
    system("ls -l $HOME | head");

    printf("\n/usr/bin files:\n");
    system("ls -l /usr/bin | head");

    printf("\n/etc files:\n");
    system("ls -l /etc | head");

    printf("\nTrying to read /etc/passwd:\n");
    system("head /etc/passwd");

    printf("\nTrying to read /etc/shadow:\n");
    system("head /etc/shadow");

    printf("\nTrying to write to /etc/test_file:\n");
    system("echo test > /etc/test_file");

    printf("\nTrying to execute /bin/ls:\n");
    system("/bin/ls > /dev/null && echo 'Execution allowed'");

    return 0;
}
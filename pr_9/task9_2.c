#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Trying to read /etc/shadow using sudo...\n");
    printf("This will work only if the current user has sudo permission.\n\n");

    int result = system("sudo cat /etc/shadow");

    if (result != 0) {
        printf("\nCommand failed. Possible reasons:\n");
        printf("- user does not have sudo rights;\n");
        printf("- sudo requires password;\n");
        printf("- access is restricted by system policy.\n");
    }

    return 0;
}
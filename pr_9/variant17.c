#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Variant 17: sudo without password security analysis\n\n");

    printf("1. Checking sudo privileges:\n");
    system("sudo -l");

    printf("\n2. Checking current user:\n");
    system("whoami");

    printf("\n3. Checking root command execution possibility:\n");
    system("sudo whoami");

    printf("\n4. Checking access to protected file /etc/shadow:\n");
    system("sudo head -n 3 /etc/shadow");

    printf("\n5. Security conclusion:\n");
    printf("If sudo commands can be executed without password, ");
    printf("then any allowed command becomes a potential privilege escalation risk.\\n");
    printf("The safest configuration is to avoid broad NOPASSWD rules ");
    printf("and allow only strictly necessary commands.\\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Current user:\n");
    system("whoami");

    printf("\nUser ID and groups:\n");
    system("id");

    return 0;
}
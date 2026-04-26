#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Creating temporary file...\n");
    system("echo 'temporary content' > temp_access_file.txt");

    printf("\nInitial permissions:\n");
    system("ls -l temp_access_file.txt");

    printf("\nChanging owner to root and permissions to 600...\n");
    system("sudo chown root:root temp_access_file.txt");
    system("sudo chmod 600 temp_access_file.txt");
    system("ls -l temp_access_file.txt");

    printf("\nTrying to read as regular user:\n");
    system("cat temp_access_file.txt");

    printf("\nTrying to write as regular user:\n");
    system("echo 'test write' >> temp_access_file.txt");

    printf("\nChanging permissions to 644 using sudo...\n");
    system("sudo chmod 644 temp_access_file.txt");
    system("ls -l temp_access_file.txt");

    printf("\nTrying to read again:\n");
    system("cat temp_access_file.txt");

    printf("\nCleaning up:\n");
    system("sudo rm -f temp_access_file.txt");

    return 0;
}
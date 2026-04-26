#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Creating file as regular user...\n");
    system("echo 'Created by regular user' > user_file.txt");

    printf("Copying file using sudo...\n");
    system("sudo cp user_file.txt copied_by_root.txt");

    printf("Changing owner to root...\n");
    system("sudo chown root:root copied_by_root.txt");

    printf("File info:\n");
    system("ls -l user_file.txt copied_by_root.txt");

    printf("\nTrying to append text as regular user...\n");
    system("echo 'new text from regular user' >> copied_by_root.txt");

    printf("\nTrying to remove file as regular user...\n");
    system("rm copied_by_root.txt");

    printf("\nFinal file info:\n");
    system("ls -l copied_by_root.txt 2>/dev/null || echo 'File was removed or is not accessible'");

    return 0;
}
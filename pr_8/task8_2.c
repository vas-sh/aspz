#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
    unsigned char data[] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};
    unsigned char buffer[4];

    int fd = open("task8_2.bin", O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    write(fd, data, sizeof(data));

    lseek(fd, 3, SEEK_SET);
    read(fd, buffer, 4);

    printf("Buffer contains: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    close(fd);
    return 0;
}
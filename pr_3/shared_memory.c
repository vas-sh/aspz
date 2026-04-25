#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = 1234;

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget failed");
        return 1;
    }

    char *data = (char*)shmat(shmid, NULL, 0);
    if (data == (char*)-1) {
        perror("shmat failed");
        return 1;
    }

    strcpy(data, "Hello from shared memory");
    printf("Data written: %s\n", data);

    shmdt(data);

    return 0;
}
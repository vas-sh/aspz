#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 64

char *shared_buffer = NULL;

void *reader_thread(void *arg) {
    (void)arg;

    for (int i = 0; i < 10; i++) {
        usleep(200000);

        if (shared_buffer != NULL) {
            printf("Reader thread: %s\n", shared_buffer);
        } else {
            printf("Reader thread: buffer is NULL\n");
        }
    }

    return NULL;
}

void *free_thread(void *arg) {
    (void)arg;

    sleep(1);

    printf("Free thread: freeing memory...\n");
    free(shared_buffer);

    return NULL;
}

int main(void) {
    pthread_t reader;
    pthread_t freer;

    shared_buffer = malloc(BUFFER_SIZE);
    if (shared_buffer == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    strcpy(shared_buffer, "Hello from shared memory buffer");

    pthread_create(&reader, NULL, reader_thread, NULL);
    pthread_create(&freer, NULL, free_thread, NULL);

    pthread_join(reader, NULL);
    pthread_join(freer, NULL);

    return 0;
}
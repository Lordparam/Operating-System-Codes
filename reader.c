#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
    int fd;
    char buffer[100];
    fd = open("myfifo", O_RDONLY);
    if (fd == -1){
        perror("open");
        return EXIT_FAILURE;
    }

    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1){
        perror("read");
        close(fd);
        return EXIT_FAILURE;
    }

    if (bytesRead > 0){
        buffer[bytesRead] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(fd);
    unlink("myfifo");
    return EXIT_SUCCESS;
}
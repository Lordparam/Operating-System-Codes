#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char buffer[100];
    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) {
        close(fd[0]); 
        char message[] = "Hello from Child";
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }

    else {
        close(fd[1]); 
        read(fd[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
        close(fd[0]);
    }

    return 0;
}

//calculate the sum of array in parent process and whether that number is prime or not in child process
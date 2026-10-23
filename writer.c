#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
    int fd;
    char message[] = "Hello from Writer!";
    if (mkfifo("myfifo", 0666) == -1){
        perror("mkfifo");
        if (access("myfifo", F_OK) == -1){
            return EXIT_FAILURE;
        }
    }

    fd = open("myfifo", O_WRONLY);
    if (fd == -1){
        perror("open");
        return EXIT_FAILURE;
    }
    write(fd, message, strlen(message) + 1);
    printf("Message sent: %s\n", message);
    close(fd);
    return EXIT_SUCCESS;
}
//to implement communication between processes ufing FIFO
//It provides byte-stream communication
//It is commonly used for communication between separate processes

//Imp system calls->
//mkfifo() create a named pipe
//open() open the FIFO
//write() sends data
//read() recieve data
//close()
//unlink()

//Writer process -> write-> named FIFO myfifo -> read -> Reader process
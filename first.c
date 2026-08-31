#include <stdio.h>
#include <unistd.h>
int main() {
    int pid;
    printf("Before fork()\n");
    pid = fork();
    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        printf("This is the child process\n");
        printf("Child PID = %d\n", getpid());
    }
    else {
        printf("This is the parent process\n");
        printf("Parent PID = %d\n", getpid());
        printf("Child PID = %d\n", pid);
    }
    return 0;
}
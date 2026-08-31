#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pid = fork();
    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }
    if (pid == 0) {
        printf("Child process id and parent pid: %d %d\n", getpid(), getppid());
        sleep(10); // child process sleeps for 10 sec, now cpu comes to parent process after parent process complete, then cpu goes to child process, but now its orphan
        printf("Child process id and parent pid: %d %d\n", getpid(), getppid());
    }
    else {
        printf("Parent process exiting...\n");
        return 0;
    }

    return 0;
}
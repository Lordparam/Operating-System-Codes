#include <stdio.h>
#include <unistd.h>
int main() {
    int pid= fork();
    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        printf("Child Process: fork() returned %d\n", pid);
    }
    else {
        printf("Parent Process: fork() returned %d\n", pid);
    }
    return 0;
}

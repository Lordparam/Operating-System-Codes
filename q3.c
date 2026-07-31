#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int pid = fork();
    if (pid == 0) {
        printf("Child Process:\n");
        for (int i = 1; i <= 5; i++) {
            printf("%d\n", i);
        }
    }
    else if (pid > 0) {
        wait(NULL);  
        printf("Parent Process: Child finished.\n");
    }
    else {
        printf("Fork has failed!\n");
    }

    return 0;
}
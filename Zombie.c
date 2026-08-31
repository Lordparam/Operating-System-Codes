#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int pid = fork();
    if (pid == 0) {
        printf("Child process exiting\n");
        return 0;
    }
    else {
        sleep(30); // child gone, parent still there
        // now can we remove entry of child process from table?
        // NO, as child has finished but not reported to parent
        wait(NULL); // this wait is again a system call that matches the child response, when parent wakes up, now you are no more a zombie
    }

    return 0;
}
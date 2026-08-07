#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    printf("No of time: %d\n", getpid());
    return 0;
}

//Write a program in which the child process is call another fork() ,in origin parent process we have sum of n numbers
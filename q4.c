#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    printf("No of time: %d\n", getpid());
    return 0;
}
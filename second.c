//⁠Parent process computes the sum of even numbers and child process computes the sum of odd numbers using fork syscall
#include <stdio.h>
#include <unistd.h>

int main() {
    int n, i;
    int evenSum = 0, oddSum = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int pid = fork();
    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        for (i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                oddSum = oddSum + i;
            }
        }
        printf("Child Process\n");
        printf("Sum of odd numbers = %d\n", oddSum);
    }
    else {
        for (i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                evenSum = evenSum + i;
            }
        }
        printf("Parent Process\n");
        printf("Sum of even numbers = %d\n", evenSum);
    }

    return 0;
}
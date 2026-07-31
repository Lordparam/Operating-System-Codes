//wap fibonaaci series upto n in child process and factorial of n in parent process
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n, i;
    printf("Enter value of n: ");
    scanf("%d", &n);
    pid_t pid = fork();
    if (pid < 0) {
        printf("Fork failed!\n");
    }
    else if (pid == 0) {
        int a = 0, b = 1, c;
        printf("Child Process PID = %d\n", getpid());
        printf("Fibonacci Series: ");
        for (i = 0; i < n; i++) {
            printf("%d ", a);
            c = a + b;
            a = b;
            b = c;
        }
        printf("\n");
    }
    else {
        int fact = 1;
        printf("Parent Process (PID = %d)\n", getpid());
        for (i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("Factorial of %d = %d\n", n, fact);
    }

    return 0;
}
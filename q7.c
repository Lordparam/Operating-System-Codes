// wacp to check whether given number is prime no if it is print its pid and ppid, if not then in the parent process calculate factorial of a given no.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n, i, prime = 1;
    int fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid == 0) {   // Inside Child Process
        if (n <= 1)
            prime = 0;
        else {
            for (i = 2; i <= n / 2; i++) {
                if (n % i == 0) {
                    prime = 0;
                    break;
                }
            }
        }
        if (prime) {
            printf("\nChild Process\n");
            printf("%d is Prime.\n", n);
            printf("PID  = %d\n", getpid());
            printf("PPID = %d\n", getppid());
        }

    } else {          // Insode of Parent Process
        wait(NULL);   
        prime = 1;
        if (n <= 1)
            prime = 0;
        else {
            for (i = 2; i <= n / 2; i++) {
                if (n % i == 0) {
                    prime = 0;
                    break;
                }
            }
        }

        if (!prime) {
            for (i = 1; i <= n; i++)
                fact *= i;

            printf("\nParent Process\n");
            printf("%d is Not Prime.\n", n);
            printf("Factorial = %llu\n", fact);
        }
    }

    return 0;
}
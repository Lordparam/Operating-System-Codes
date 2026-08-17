//wap to find sum of elements in an array within child process and trhen chekc whteher sum is prime or not in the parent process, in C

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 11};
    int n = 5;
    int sum = 0;

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork Failed!\n");
        return 1;
    }
    if (pid == 0)
    {

        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
        }
        printf("Child Process\n");
        printf("Sum = %d\n", sum);
    }
    else
    {
        wait(NULL);
        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
        }

        printf("Parent Process\n");

        if (isPrime(sum))
            printf("%d is Prime\n", sum);
        else
            printf("%d is Not Prime\n", sum);
    }
    return 0;
}
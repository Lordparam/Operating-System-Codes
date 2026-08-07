// wacp to call a functiion fibonacci in the child process and print the fibonacci series upto n, ans in the parent process call a funcrtion armstring and print all armstrong upto n

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
void fibonacci(int n){
    int a = 0, b = 1, c;
    printf("\nChild Process\n");
    printf("Fibonacci Series: ");
    while (a <= n)
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

void armstrong(int n){
    int i, num, rem, sum;
    printf("\nParent Process\n");
    printf("Armstrong Numbers: ");
    for (i = 1; i <= n; i++)
    {
        num = i;
        sum = 0;
        while (num > 0)
        {
            rem = num % 10;
            sum = sum + rem * rem * rem;
            num = num / 10;
        }
        if (sum == i)
            printf("%d ", i);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    pid_t pid = fork();
    if(pid < 0){
    
        printf("Fork Failed!\n");
        return 1;
    }
    if(pid == 0) { 
    
        fibonacci(n);
    }
    else {
    
        wait(NULL);
        armstrong(n);
    }
    return 0;
}
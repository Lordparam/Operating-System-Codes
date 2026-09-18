#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int arr[]={2, 4, 6, 3, 5};
    int n=5;
    int sum=0;
    int pipefd[2];
    pipe(pipefd);
    pid_t pid = fork();
    if(pid > 0){
        close(pipefd[0]);
        for (int i =0;i < n;i++) {
            sum = sum + arr[i];
        }
        printf("Parent: Sum = %d\n", sum);
        write(pipefd[1], &sum, sizeof(sum));
        close(pipefd[1]);
        wait(NULL);
    }
    else if(pid == 0){
        int num;
        int prime = 1;
        close(pipefd[1]);
        read(pipefd[0], &num, sizeof(num));
        close(pipefd[0]);
        if(num<2){
            prime=0;
        }
        else{
            for(int i=2;i<num;i++) {
                if (num%i==0) {
                    prime=0;
                    break;
                }
            }
        }

        if (prime)
            printf("Child: %d is Prime\n", num);
        else
            printf("Child: %d is Not Prime\n", num);
    }

    return 0;
}


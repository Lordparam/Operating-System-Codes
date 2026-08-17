//wap to read string from the user within child process and then print all the premutations of the characters of given string

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void permutation(char str[], int start, int end)
{
    int i;
    char temp;
    if (start == end)
    {
        printf("%s\n", str);
        return;
    }
    for (i = start; i <= end; i++)
    {
        temp = str[start];
        str[start] = str[i];
        str[i] = temp;
        permutation(str, start + 1, end);
        temp = str[start];
        str[start] = str[i];
        str[i] = temp;
    }
}

int main()
{
    char str[100];
    int n = 0;
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Fork Failed!\n");
        return 1;
    }
    if (pid == 0)
    {

        printf("Enter a string: ");
        scanf("%s", str);

        while (str[n] != '\0')
        {
            n++;
        }

        printf("\nChild Process\n");
        printf("Permutations:\n");

        permutation(str, 0, n - 1);
    }
    else
    {
        wait(NULL);
        printf("\nParent Process\n");
        printf("Child process completed.\n");
    }

    return 0;
}
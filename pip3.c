//write a c program to create input.txt in parent process and write ur name university roll and class roll no in it and then read same file in child process and print the content

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char name[50];
    int university_roll, class_roll;
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter University Roll No: ");
    scanf("%d", &university_roll);

    printf("Enter Class Roll No: ");
    scanf("%d", &class_roll);

    pid_t pid = fork();

    if (pid > 0) {
        FILE *fp;
        fp = fopen("input.txt", "w");
        if (fp == NULL) {
            printf("File cannot be created.\n");
            return 1;
        }
        fprintf(fp, "Name: %s", name);
        fprintf(fp, "University Roll No: %d\n", university_roll);
        fprintf(fp, "Class Roll No: %d\n", class_roll);
        fclose(fp);
        printf("\nParent: Data written to input.txt\n");
        wait(NULL);
    }
    else if (pid == 0) {
        FILE *fp;
        char ch;
        fp = fopen("input.txt", "r");
        if (fp == NULL) {
            printf("File cannot be opened.\n");
            return 1;
        }
        printf("\nChild: Contents of input.txt\n\n");
        while ((ch = fgetc(fp)) != EOF) {
            printf("%c", ch);
        }
        fclose(fp);
    }
    else {
        printf("Fork failed.\n");
    }
    return 0;
}
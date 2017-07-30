#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char ch1 = 'g';
    char ch2 = 's';
    char *ptr;

    printf("Char 1 is %c\n", ch1);
    printf("Char 2 is %c\n", ch2);
    printf("Address of Char 1 is %p\n", &ch1);
    printf("Address of Char 2 is %p\n", &ch2);
    ptr = &ch1;
    ch2 = *ptr;
    printf("Char 1 is %c\n", ch1);
    printf("Char 2 is %c\n", ch2);
    printf("Address of ptr is %p\n", ptr);
    printf("The current process %d \n", getpid());
    printf("The parent process is %d \n", getppid());
    printf("The owner of this process has uid %d \n", getuid());
    sleep(1);
    int A[] = {1, 2, 3, 4, 5, 6};
    int sum = 0, pdt = 1, PID, i;
    if ((PID = fork()) == 0)
    {
        for (i = 0; i < 6; i++)
            sum += A[i];
        printf("This is child process computed sum %d \n", sum);
    }
    if (PID < 0)
    {
        fprintf(stderr, "problem creating a process \n");
    }
    if (PID > 0)
    {
        for (i = 0; i < 6; i++)
            pdt *= A[i];
        printf("The parent process completed the product %d \n", pdt);
    }
    int child_status, pid, pidwait;
    if ((pid = fork()) == 0)
    {
        printf("This is the child !\n");
    }
    else
    {
        pidwait = wait(&child_status);
        printf("child % d has terminated\n", pidwait);
    }
    exit(0);
     return 0;
}
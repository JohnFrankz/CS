#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
 
int main()
{
    int pid = fork();

    if (pid > 0) {
        printf("Parent pid: %d\n", getpid());
        printf("parent: child=%d\n", pid);
        pid = wait((int *) 0);
        printf("Child pid: %d\n", pid);
    } else if (pid == 0) {
        printf("Child: exiting\n");
        exit(0);
    } else {
        printf("fork error\n");
    }
}
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    char *argv[3];

    // argv[0] = "echo";
    // argv[1] = "hello";
    // argv[2] = 0;
    // execv("/bin/echo", argv);
    // printf("exec error\n");

    // char *binarypath = "/bin/ls";
    // char *arg1 = "-lh";
    // char *arg2 = "/home";
    // // execl(binarypath, binarypath, arg1, arg2, NULL);
    // execlp(binarypath, binarypath, arg1, arg2, NULL);

    // char *binaryPath = "/bin/ls";
    // char *args[] = {binaryPath, "-lh", "/home", 0 };
    // execv(binaryPath, args);

    // char *programName = "ls";
    // char *args[] = {programName, "-lh", "/home", NULL };
    // execvp(programName, args);

    // int execle(const char * path, const char *arg, ..., NULL, char * const envp[]);
    char *binaryPath = "/bin/bash";
    char *arg1 = "-c";
    char *arg2 = " echo \"Visit $HOSTNAME:$PORT from your browser .\"";
    char *const env[] = {"HOSTNAME=www.linuxhint.com", "PORT=8080", NULL};
    execle(binaryPath, binaryPath,arg1, arg2, NULL , env);
}


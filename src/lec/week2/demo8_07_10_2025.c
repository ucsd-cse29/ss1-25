#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
#include <string.h>
#include <sys/wait.h>

#define MAX_SIZE 512

int main(int argc, char *argv[]) {
    while (1) {
        printf("~> ");
        char command[MAX_SIZE];
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = 0;
        pid_t pid = fork();
        if (pid < 0) {
            printf("Fork() failed\n");
        } else if (pid == 0) {
            // I am child, run command
            // char arg0[MAX_SIZE];
            // char arg1[MAX_SIZE];
            // sscanf(command, "%s %s", arg0, arg1);
            int argc = 0;
            char *argv[MAX_SIZE];
            char *token = strtok(command, " \t\n");
            while(token) {
                argv[argc] = token;
                argc++;
                token = strtok(NULL, " \t\n");
            }
            argv[argc] = NULL;
            execvp(argv[0], argv);
            printf("Command not found %s\n", command);
        } else {
            // I am the parent
            wait(NULL);
        }
    }
}






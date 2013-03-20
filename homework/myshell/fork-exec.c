#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * This program demonstrates the use of the fork() and exec()
 * functions.
 */
int main() {
    while(1){
        /* String to hold the command to run. */
        char input[256];
        char command[256];
        char modifier[256];
        char current = command[0];
        int index = 0;
        int length = 0;

        printf("Enter the command to run: ");
        scanf("%[^\n]%*c", input);
        
        //find the command
        while(isspace(current) == 0) {
            command[index] = input[index];
            index = index + 1;
            current = input[index];
        }
        
        current = input[index + 1];
        index += 1;
        int newIndex = 0;
        
        //find the modifier
        while(isspace(current) == 0) {
            modifier[newIndex] = input[index];
            index = index + 1;
            newIndex = newIndex + 1;
            current = input[index];
        }
        /* Variable that will store the fork result. */
        pid_t pid;
        
        /* Perform the actual fork. */
        pid = fork();
        if (pid < 0) {
            /* Error condition. */
            fprintf(stderr, "Fork failed\n");
            return -1;
        } else if (pid == 0) {
            /* Child process. */
            printf("Running...\n");
            if (strcmp(command, "cd")  == 0) {
                chdir(modifier);
            }
            execlp(command, command, NULL);
        } else {
            /* Parent process. */
            int result;
            
            if (modifier[0] != '&') {
                wait(&result);
            }
            
            
            printf("All done; result = %d\n", result);
        }

    }

    return 0;
}

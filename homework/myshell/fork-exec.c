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
        char current = 0;
        int index = 0;
        int length = 0;

        printf("Enter the command to run: ");
        current = getchar();
        /*
        scanf("%[^\n]%*c", input);
        printf("%s\n", input);*/
        //find the command
        
        while(isspace(current) == 0) {
            command[index] = current;
            current = getchar();
            index += 1;
            if (current == -1) {
                printf("\n");
                return 0;
            }
        }

        // JD: This still parses incompletely.  You can't do more
        //     than one argument, and if you enter a command with
        //     an argument followed by a command without one, that
        //     prior argument "sticks."
        if (current != '\r' && current != '\n') {
            current = getchar();
            index = 0;
            //find the modifier
            // JD: What if the command has arguments (e.g., ls -l
            //     or ping localhost)?
            while(isspace(current) == 0) {
                modifier[index] = current;
                index += 1;
                current = getchar();
                if(current == -1) {
                    printf("\n");
                    return 0;
                }
            }
        }
        printf("Modifier is %s\n", modifier);
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
            // JD: You are performing the cd here, in the child.  Think
            //     about that...
            // JD: You should look up execlp (or the other forms of exec)
            //     in order to call this completely correctly.
            
            if (strlen(modifier) > 1 ) {
                execlp(command, command, modifier, NULL);
            } else {
                execlp(command, command, NULL);
            }
        } else {
            /* Parent process. */
            int result;

            // JD: This only catches & as the first character of the
            //     first argument.  Unfortunately, that means
            //     "ping localhost &" will not work.
            if (modifier[0] != '&') {
                wait(&result);
            }
            
            if (strcmp(command, "cd")  == 0) {
                chdir(modifier);
            }
            printf("All done; result = %d\n", result);
        }

    }

    return 0;
}

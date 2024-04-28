// Program 1 : Parent Process
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Create a child process
    pid_t pid = fork();

    if (pid < 0) { // Error handling for fork failure
        perror("Fork failed");
        return 1;
    } else if (pid == 0) { // Child process block
        printf("Child process created. PID: %d\n", getpid());
        
        // Call the second program using execv
        char *args[] = {"./second_program", NULL}; // Modify the executable name as needed
        execv(args[0], args); // Execute the second program
        
        // If execv fails, it returns, so we need error handling
        perror("Exec failed");
        return 1;
    } else { // Parent process block
        // Wait for the child to finish
        int status;
        waitpid(pid, &status, 0);
        printf("Child process terminated with status: %d\n", WEXITSTATUS(status));
    }

    return 0;
}


// Program 2 : Second Program to be Executed by the Child

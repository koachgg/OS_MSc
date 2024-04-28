#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t pid = fork();

  if (pid == 0) {
    // Child process
    printf("Hello from child process!\n");
    execlp("ls", "ls", "-l", NULL); // Execute ls command with arguments
    perror("execlp"); // Print error if execlp fails
    exit(1);  // Exit child process with an error code if execlp fails
  } else if (pid > 0) {
    // Parent process
    printf("Parent waiting for child...\n");
    int status;
    waitpid(pid, &status, 0);  // Wait for child process to finish

    // Check the child's exit status
    if (WIFEXITED(status)) {
      int child_exit_code = WEXITSTATUS(status);
      printf("Child process exited with status: %d\n", child_exit_code);
    } else {
      printf("Child process terminated abnormally.\n");
    }
  } else {
    // Error handling for fork failure
    perror("fork");
    exit(1);
  }

  return 0;
}

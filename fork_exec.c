/*
The following code may/may not execute on your system likely because your development environment doesn't support POSIX system calls, but will easily work on online gdb compiler / WSL/ Linux OS
  */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
  pid_t pidFork = fork();

  if (pidFork < 0)
    fprintf(stderr, "Error in fork()\n");
  else if (pidFork > 0)
  {
    wait(NULL);
    printf("PARENT: Child Exited\n");
  }
  else
  {
    printf("CHILD: Parent Process ID: %d\n", getppid());
    printf("CHILD: Process ID: %d\n", getpid());
    exit(0);
  }

  return 0;
}

/*
  The code given below is also correct, run either of the codes 



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int a;
	a=fork();
	if(a<0)
	{
    	printf("child process could not be created");
    	exit(-1);
  	}
  	else if(a==0)
  	{
  		printf("Child process : My ID is %d\n",getpid());
  	}
  	else
  	{ 
  		wait(NULL);
  		printf("Parent process : My ID is %d\n",getpid());
  	}
  */

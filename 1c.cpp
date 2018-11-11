// C. before terminating, the parent waits for the child to finish its task
 #include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
 int main()
 {
	int pid;
	pid=fork();
	if(pid<0)
{
		printf("\n error");
	exit(1);
}
 else if (pid==0)
 
 { 
   printf("\n Hello i am a child process");
   printf("\n my pid is %d",getpid());
   exit(0);
 }
 else if (pid>0)
 {
 	printf("\n I am parent process");
 	printf("\n My actual pid is %d \n", getpid());
 	
 	wait(NULL);
 	exit(1);
 	
 }
	
	}

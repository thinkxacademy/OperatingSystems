// PROGRAM - 1
// Write a program (using Fork() and /or Exec() commands ) where parents and child execute :
// A. same program ,same code
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	pid_t pid ,p;
	
	p=fork();
	pid = getpid();
	if (p<0)
	{
		fprintf(stderr,"Fork Failed");
		return 1;
	}
	 printf("Output of fork id : %d\n",p);
	 printf("process id is : %d \n",pid);
	 return 0;
	
}

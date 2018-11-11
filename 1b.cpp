// B. same program different code
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
 int main()
 {
	int pid;
	pid=fork();
	if(pid<0){
	
	printf("\n error");
	exit(1);
}
	else if (pid==0){
	
	printf("\n Hello I am child process");
	printf("\n My pid is %d" ,getpid());
	exit(0);
}
	else
	 { printf("\n Hello i am parent process");
	 
	 printf("\n My actual pid is %d \n",getpid());
	 exit(1);
}
	 }

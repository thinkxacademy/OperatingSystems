#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int a;
	printf("\nkernel version:\n");
	system("cat/proc/sys/kernel/osrelease");
	printf("\nCPU TYPE & MODEL:\n");
	system("cat/proc/cpuinfo|awk 'NR==4,NR==5{print}'");
	printf("\nInformation on COnfigured amount of free and used Memory:\n");
	system("cat/proc/memInfo|awk'NR==1,NR==2{print}'");
	return 0;
}

#include<stdio.h>
#include<sys/stat.h>
int main(int argc,char*argv[3])
{
int i;
struct stat buffer;
if(argc<2)
printf("give file name");
for(i=1;i<argc;i++)
{
  printf("file=%s\n",argv[i]);
  if(stat(argv[i],&buffer)<0)
       printf("error in file starting");
  else
  {     
       printf("Owenered=%d\ngid=%d\n",buffer.st_uid,buffer.st_gid);
       printf("Access permission=%d\n",buffer.st_mode);
       printf("Access time=%d\n",(time(&(buffer.st_atime))));
  }


}
}

/*Write a menu driven program to implement Memory Management alogorithms  1.First Fit  2.Best Fit  3.Worst Fit*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void accept(int a[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
	       scanf("%d",&a[i]) ;
	}
}
void display(int a[],int n)
{
	int i;
	printf("\n\n");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
}
void sort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
	  for(j=0;j<n-1;j++)
	  {
	  	if(a[j]>a[j+1]);
		  {
		  	temp=a[j];
		  	a[j]=a[j+1];
		  	a[j+1]=temp;
		  }
	  }
     }
}	
void first_fit(int psize[],int np,int msize[],int nm)
{
	int i,j,itot,etot,flag[30]={0};
	itot=etot=0;
	for(i=0;i<np;i++)
	{
		for(j=0;j<nm;j++)
		{
			if(flag[j]==0&&msize[j]>=psize[i])
			{
				flag[j]=1;
				itot=itot+msize[j]-psize[i];
				break;
			}
		}
		if(j==nm)
		printf("\n\n There is no space for process %d",i);
	}
	for(i=0;i<nm;i++)
	{
		if(flag[i]==0)
		etot=etot+msize[i];
	}
	printf("\n\n Processes :");
	display(psize,np);
	printf("\n\n Memory Holes :");
	display(msize,nm);
	printf("\n\n Total Sum of Internal Fragmentation= %d",itot);
	printf("\n\n Total Sum of External Fragmentation= %d",etot);
}
void best_fit(int psize[],int np,int msize[],int nm)
{
	int i,j,itot,etot,temp[30],flag[30]={0};
	itot=etot=0;
	
	for(i=0;i<nm;i++)
	temp[i]=msize[i];
	sort(temp,nm);
	for(i=0;i<np;i++)
	{
	   for(j=0;j<nm;j++)
	    {
	    	if(flag[j]==0&&temp[j]>=psize[i])
	    	{
	    		flag[j]=1;
	    		itot=itot+temp[j]-psize[i];
	    		break;
			}
	    }
	    if(j==nm)
	    printf("\n\n There is no Space for Process %d",i);
	}
	for(i=0;i<nm;i++)
	{
		if (flag[i]==0)
		etot=etot+temp[i];		
	}
printf("\n\n Processes :");
display(psize,np);
printf("\n\n Memory Holes:");
display(temp,nm);
printf("\n\n total Sum of Internal Fragmentation =%d",itot);
printf("\n\n total Sum of External Fragmentation =%d",etot);
}





void worst_fit(int psize[],int np,int msize[],int nm)
{
	int i,j,itot,etot,temp[30],flag[30]={0};
	itot=etot=0;
	
	for(i=0;i<nm;i++)
	temp[i]=msize[i];
	sort(temp,nm);
	for(i=0;i<np;i++)
	{
	   for(j=nm-1;j>=nm;j--)
	    {
	    	if(flag[j]==0&&temp[j]>=psize[i])
	    	{
	    		flag[j]=1;
	    		itot=itot+temp[j]-psize[i];
	    		break;
			}
	    }
	    if(j==nm)
	    printf("\n\n There is no Space for Process %d",i);
	}
	for(i=0;i<nm;i++)
	{
		if (flag[i]==0)
		etot=etot+temp[i];		
	}
printf("\n\n Processes :");
display(psize,np);
printf("\n\n Memory Holes:");
display(temp,nm);
printf("\n\n total Sum of Internal Fragmentation =%d",itot);
printf("\n\n total Sum of External Fragmentation =%d",etot);
}
/*****************************************************************************************/
void main()
{
int ch,np,nm,psize[30],msize[30];	
printf("\n Enter number of Processes:");
scanf("%d",&np);
printf("\n\n Enter sizes of Processes");
accept(psize,np);
printf("\n Enter number of Memory Holes");
scanf("%d",&nm);
printf("\n\n Enter sizes of Memory Holes");
accept(msize,nm);	
while(1)
{
printf("\n\n\t\t **Main Menu**");
printf("\n\n\t Memory Mangaement");
printf("\n\n\t 1.First Fit");
printf("\n\n\t 2.Best Fit");
printf("\n\n\t 3.Worst Fit");
printf("\n\n\t 4.Quit");

printf("\n\n Enter your choice:");
scanf("%d",&ch);
switch(ch)
{
	case 1:
		printf("\n\n First Fit:\n");
		first_fit(psize,np,msize,nm);
		break;
	case 2:
		printf("\n\n Best Fit:\n");
		best_fit(psize,np,msize,nm);
		break;
		
	case 3:
		printf("\n\n Worst Fit:\n");
		worst_fit(psize,np,msize,nm);
		break;
	case 4:
		exit(0);
	default:
		printf("\n\n please enter correct Choice!!");
}
}
}

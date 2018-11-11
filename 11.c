#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,time,sum_wait=0,sum_turnaround=0,endTime,smallest;
    int at[10],bt[10],rt[10],remain=0;//rt=remaining Time
    printf("Enter no of Processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time for process p%d :",i+1);
        scanf("%d",&at[i]);
        printf("Enter burst time for process p%d :",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    rt[9]=9999;
    printf("\n\nProcess\t|Turnaroundtime|waiting time \n\n");
    for(time=0;remain!=n;time++)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time&&rt[i]<rt[smallest]&&rt[i]>0)
            {
                smallest=i;
            }
        }
        rt[smallest]--;
        if(rt[smallest]==0)
        {
            remain++;
            endTime=time+1;
            printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,endTime-at[smallest],endTime-bt[smallest]-at[smallest]);
            sum_wait+=endTime-bt[smallest]-at[smallest];
            sum_turnaround+=endTime-at[smallest];
        }
    }
    printf("\nAverage waiting time = %f\n",sum_wait*1.0/n);
    printf("\nAverage turnaround time = %f\n",sum_turnaround*1.0/n);
    return 0;

}


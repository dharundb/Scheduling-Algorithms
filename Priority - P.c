//Priority Scheduling - Preemptive

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Process{
int p,at,ct,pr,bt,tt,wt;
//process, arrival time,completion time,priority, burst time, turn around time, waiting time
};

int main()
{
    int i,j,n;
    printf("\t\t\t\t\tPRIORITY SCHEDULING- PREEMPTIVE");
    printf("\nEnter the number of processes:");
    scanf("%d",&n);
    printf("\n");
    struct Process p[n];
    int bt[n];
    for(i=0;i<n;i++){
        printf("Enter the process's id: ");
        scanf("%d",&p[i].p);
        printf("Enter the arrival time: ");
        scanf("%d",&p[i].at);
        printf("Enter the Burst Time: ");
        scanf("%d",&p[i].bt);
        bt[i]=p[i].bt;
        printf("Enter Priority: ");
        scanf("%d",&p[i].pr);
        printf("\n");
    }
     int complete=0, min=0, time=0;
     for(time=0;complete<n;time++){
        int flag=0,index=0;
        int m_pri=INT_MAX;
        for(i=0;i<n;i++){
            if(p[i].at<=time && bt[i]>0 && p[i].pr<m_pri){
                index=i;
                flag=1;
                m_pri=p[i].pr;
            }
        }
        if(flag==1){
            bt[index]-=1;
            if(bt[index]==0){
                complete+=1;
                p[index].ct=time+1;
            }
        }
    }
    int sum1=0; //for ATT
    int sum2=0; //for AWT
    for(i=0;i<n;i++){
        p[i].tt=abs(p[i].ct-p[i].at);
        p[i].wt=abs(p[i].tt-p[i].bt);
        sum1+=p[i].tt;
        sum2+=p[i].wt;
    }

    printf("Process\tAT\tBT\tPriority\tCT\tTT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",p[i].p,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].tt,p[i].wt);
    }
    float att= (float)sum1/n;
    float awt= (float)sum2/n;
    printf("\nAverage Turn Around Time : %.2f",att);
    printf("\nAverage Waiting time : %.2f",awt);
}

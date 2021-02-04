//Priority Scheduling - Non Preemptive 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process{
int p,at,ct,pr,bt,tt,wt;
//process, arrival time,completion time,priority, burst time, turn around time, waiting time
};

int main()
{
    int i,j,n;
    printf("\t\tPRIORITY SCHEDULING- NON PREEMPTIVE");
    printf("\nEnter the number of processes:");
    scanf("%d",&n);
    printf("\n");
    struct Process p[n];
    struct Process temp;
    for(i=0;i<n;i++){
        printf("Enter the process's id: ");
        scanf("%d",&p[i].p);
        printf("Enter the arrival time: ");
        scanf("%d",&p[i].at);
        printf("Enter the Burst Time: ");
        scanf("%d",&p[i].bt);
        printf("Enter Priority: ");
        scanf("%d",&p[i].pr);
        printf("\n");
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(p[i].pr<p[j].pr){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        if(i==0){
            p[i].ct=p[i].bt+p[i].at;
        }
        else{
            p[i].ct=p[i-1].ct+p[i].bt;
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
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(p[i].p<p[j].p){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
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



//Shortest Job First Scheduling

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process{
int p,at,ct,bt,tt,wt;
//process, arrival time,completion time, burst time, turn around time, waiting time
};

int main()
{
    int i,j,n;
    printf("\t\t\t\t\tSHORTEST JOB FIRST - NON PREEMPTIVE");
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
        printf("\n");
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(p[i].bt<p[j].bt){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(i=1;i<n;i++){
        if(p[i-1].bt==p[i].bt){
                if(p[i-1].p>p[i].p){
                    temp=p[i-1];
                    p[i-1]=p[i];
                    p[i]=temp;
                }
        }
        else{
            continue;
        }
    }
    for(i=0;i<n;i++){
        if(i==0){
            p[i].ct=p[i].bt;
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
    printf("Process\tAT\tBT\tCT\tTT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].p,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
    }
    float att= (float)sum1/n;
    float awt= (float)sum2/n;
    printf("\nAverage Turn Around Time : %.2f",att);
    printf("\nAverage Waiting time : %.2f",awt);
}


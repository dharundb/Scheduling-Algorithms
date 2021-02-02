#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Process{
int p,at,bt,ct,tt,wt;
//process id, arrival time, burst time, completion time, turn around time, waiting time
};

int main(){
    int i,j,n,tq;
    printf("\t\tROUND ROBIN SCHEDULING");
    printf("\nEnter the no. of process:");
    scanf("%d",&n);
    printf("\nEnter time quantum:");
    scanf("%d",&tq);
    struct Process p[n];
    struct Process temp;
    int bt[n];
    printf("\n");
    for(i=0;i<n;i++){
        printf("Enter the process's id: ");
        scanf("%d",&p[i].p);
        printf("Enter the arrival time: ");
        scanf("%d",&p[i].at);
        printf("Enter the Burst Time: ");
        scanf("%d",&p[i].bt);
        bt[i]=p[i].bt;
        printf("\n");
    }
    for(i=0;i<n;i++){
        int flag=0;
        for(j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
    int complete=0,time=0,index=-1,front=-1,rear=-1;
    int queue[1000], process[n];
    for(i=0;i<n;i++){
        process[i]=0;
    }
    while(complete<n){
        if((front==-1)&&(rear==-1)){
            time=p[index+1].at;
            queue[++front]=index+1;
            queue[++rear]=index+1;
            process[index+1]=1;
        }
        else if(rear<front){
            rear=-1;
            front=-1;
        }
        else{
            index=queue[front];
            front=front+1;
            if(bt[index]>0){
                if(bt[index]>tq){
                    time+=tq;
                    bt[index]=bt[index]-tq;
                    for(i=index+1;i<n;i++){
                        if(p[i].at<=time && process[i]==0){
                            queue[++rear]=i;
                            process[i]=1;
                        }
                    }
                    queue[++rear]=index;
                }
                else if(bt[index]<=tq){
                    time+=bt[index];
                    bt[index]=0;
                    p[index].ct=time;
                    complete+=1;
                    for(i=index+1;i<n;i++){
                        if(p[i].at<=time && process[i]==0){
                            queue[++rear]=i;
                            process[i]=1;
                        }
                    }
                }
            }
        }
    }
    float sum1=0; //for ATT
    float sum2=0; //for AWT
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
    float att= sum1/n;
    float awt=sum2/n;
    printf("\nAverage Turn Around Time : %.2f",att);
    printf("\nAverage Waiting time : %.2f",awt);
}

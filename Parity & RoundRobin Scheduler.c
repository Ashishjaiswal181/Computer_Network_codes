#include <stdio.h>
#include <stdlib.h>
//#include <pthread.h>
#define max 100
/*
 * @author Ashish_kumar
 */
typedef struct parameters{
    int servers,burst[max],priority[max],tslice;
}p;
void priority(struct parameters p){
    int i,temp1,temp2,pos,j,sum_waiting=0,sum_turnaround=0,waiting=0,turnaround=0;
    //int a[p.servers];
    for(j=0;j<p.servers;j++){
        temp1=p.priority[j];
        for(i=j;i<p.servers;i++){
            if(temp1<=p.priority[i]){
                temp1=p.priority[i];
                pos=i;}}
        temp2=p.priority[j];
        p.priority[j]=temp1;
        p.priority[pos]=temp2;
        temp2=p.burst[j];
        p.burst[j]=p.burst[pos];
        p.burst[pos]=temp2;
        //a[j]=pos;
    }
    float avg_waiting,avg_turnaround;
    printf("Assuming all servers arrived at the same time = 0.\n");
    for(i=0;i<p.servers;i++){
        if(i!=0)
            waiting=p.burst[i-1]+waiting;
        sum_waiting=sum_waiting+waiting;
        turnaround=p.burst[i]+waiting;
        sum_turnaround=sum_turnaround+turnaround;}
    avg_waiting=(float)sum_waiting/p.servers;
    avg_turnaround=(float)sum_turnaround/p.servers;
    printf("The average waiting time is %f.\n",avg_waiting);
    printf("The average turnaround time is %f.\n",avg_turnaround);
}
void round_robin(struct parameters p){
    int i,temp1=0,j,sum_waiting=0,sum_turnaround=0,count=0;
    int ts[p.servers],tf[p.servers];
    for(i=0;i<p.servers;i++){
        tf[i]=0;
        sum_turnaround=sum_turnaround+p.burst[i];}
    printf("Assuming that all servers arrives at the same time = 0.\n");
    for(j=0;;j++){
        for(i=0;i<p.servers;i++){
            if(p.burst[i]>p.tslice){
                ts[i]=temp1;
                p.burst[i]=p.burst[i]-p.tslice;
                temp1=temp1+p.tslice;
                sum_waiting=sum_waiting+ts[i]-tf[i];
                tf[i]=temp1;}
            else if(p.burst[i]==0){}
            else{
                ts[i]=temp1;
                temp1=temp1+p.burst[i];
                p.burst[i]=0;
                sum_waiting=sum_waiting+ts[i]-tf[i];
                tf[i]=temp1;
                count++;}}
        if(count==p.servers)
            break;}
    sum_turnaround=sum_turnaround+sum_waiting;
    float avg_waiting=(float)sum_waiting/p.servers;
    float avg_turnaround=(float)sum_turnaround/p.servers;
    printf("The average waiting time is %f.\n",avg_waiting);
    printf("The average turnaround time is %f.\n",avg_turnaround);
}
int main() {
    //int status1,status2,i;
    int i;
    //pthread_t thre1,thre2;
    struct parameters p;
    printf("Enter the number of servers.\n");
    scanf("%d",&p.servers);
    printf("Enter the CPU burst time and priority for each process.\n");
    for(i=0;i<p.servers;i++){
        scanf("%d",&p.burst[i]);
        scanf("%d",&p.priority[i]);}
    printf("Enter the size of the time slice: ");
    scanf("%d",&p.tslice);
    printf("The scheduling using priority scheduler. \n");
    priority(p);
    printf("\n\nThe scheduling using round robin scheduler.\n");
    round_robin(p);
    /*status1=pthread_create(&thre1,NULL,priority,&p);
    pthread_join(thre1,NULL);
    status2=pthread_create(&thre2,NULL,round_robin,&p);
    pthread_join(thre1,NULL);
    if(status1||status2){
        printf("Error");
        exit(-1);
    }*/
    return (EXIT_SUCCESS);
}


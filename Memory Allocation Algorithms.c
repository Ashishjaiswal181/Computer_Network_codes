#include <stdio.h>
#include <stdlib.h>

void first_fit(int n,int m, int block[n],int process[m])
{
    int i,j,f;
    for(i=0;i<m;i++)
    {
        f=0;
        printf("Process %d ",i+1);
        for(j=0;j<n&&f==0;j++)
        {
            if(process[i]<=block[j])
            {
                block[j]=block[j]-process[i];
                printf("allocated to block %d\n",j+1);
                f=1;
            }
        }
        if(f==0)
            printf("not allocated to memory\n");
    }
}

void best_fit(int n,int m, int block[n],int process[m])
{
    int i,j,f,temp[n],temp1;
    for(i=0;i<m;i++)
    {
        f=0;temp1=999;
        printf("Process %d ",i+1);
        for(j=0;j<n;j++)
        {
            if(process[i]<=block[j])
                temp[j]=block[j]-process[i];
            else
                temp[j]=999;
            if(temp1>=temp[j])
                temp1=temp[j];
        }
        for(j=0;j<n&&f==0;j++)
        {
            if(temp1==temp[j])
            {
                block[j]=block[j]-process[i];
                printf("allocated to block %d\n",j+1);
                f=1;
            }
        }
        if(f==0)
            printf("not allocated to memory\n");
    }
}

void worst_fit(int n,int m, int block[n],int process[m])
{
    int i,j,f,temp[n],temp1;
    for(i=0;i<m;i++)
    {
        f=0;temp1=0;
        printf("Process %d ",i+1);
        for(j=0;j<n;j++)
        {
            if(process[i]<=block[j])
                temp[j]=block[j]-process[i];
            else
                temp[j]=-1;
            if(temp1<=temp[j])
                temp1=temp[j];
        }
        for(j=0;j<n&&f==0;j++)
        {
            if(temp1==temp[j])
            {
                block[j]=block[j]-process[i];
                printf("allocated to block %d\n",j+1);
                f=1;
            }
        }
        if(f==0)
            printf("not allocated to memory\n");
    }
}

int main()
{
    int n,m,i,choice;
    printf("Enter the number of block");
    scanf("%d",&n);
    printf("Enter the number of processes");
    scanf("%d",&m);
    int block[n],process[m];
    printf("Enter the sizes of the blocks");
    for(i=0;i<n;i++)
        scanf("%d",&block[i]);
    printf("Enter the sizes of the processes");
    for(i=0;i<m;i++)
        scanf("%d",&process[i]);
    printf("choose the memory management algorithm\n");
    printf("1. First fit\n2. Best fit\n3. Worst fit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:first_fit(n,m,block,process);
                break;
        case 2:best_fit(n,m,block,process);
                break;
        case 3:worst_fit(n,m,block,process);
                break;
        default:printf("Wrong choice\n");
    }
    return 0;
}

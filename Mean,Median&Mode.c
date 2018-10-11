#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
int main()
{
    int value[max],n,i=0,d=0,x[max],mode=0,p=0,sum=0,c=0,j=0;
    float mean=0.0,median=0.0;
    printf("Enter the number of data values \n");
    scanf("%d",&n);
    printf("Enter the data values\n");
   for(i=0;i<n;i++)
        scanf("%d",&value[i]);
    if(n%2!=0)
        median=value[n/2];
    else
        median=(float) (value[(n-1)/2]+value[n/2])/2;
   for(i=0;i<n;i++)
       {
   for(j=0;j<n;j++)
  {
if(value[i]>=value[j])
{
int temp=value[j];
value[j]=value[i];
value[i]=temp;
}
}}
   for(j=0;j<n;j++)
     {
       if(value[j]==value[j+1])
            c++;
             else{
            if(d<=c&&c>=1)
                    d=c;
                    c=0;}}
    for(i=0;i<n;i++)
{
       if(value[i]==value[i+1])
            c++;
            else{
            if(c==d&&c>=1)
                {
                        x[p]=value[i];
                        p++;}
            c=0;
        }
     }
     for(i=0;i<n;i++)
      sum=sum+value[i];
    mean=(sum/n);
    printf("Mean =%f ; median =%f ; mode = ",mean,median);
    if(x[0]>0)
       {
        for(i=p-1;i>=0;i--)
        printf("%d ",x[i]);
        }
    return 0;
}

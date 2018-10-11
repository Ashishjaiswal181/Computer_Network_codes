#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i=0,j=0,k=0,sum=0,key=0;
    printf("Enter the size of input sequence ");
    scanf("%d",&n);
    int arr[n],mat[n][n];
    printf("Enter the input values \n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            sum=0;
            for(k=i;k<=j;k++)
            {
                sum=sum+arr[k];
            }
            mat[i][j]=sum;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(key<=mat[i][j])
            {
                key=mat[i][j];
            }
        }
    }
    printf("\nMax sum of contagious subsequence is %d",key);
}

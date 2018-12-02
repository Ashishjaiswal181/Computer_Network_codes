#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,j,m,count=0,count1=0,k,l;
    printf("Enter the number of resources");
    scanf("%d",&n);
    printf("Enter the number of processors");
    scanf("%d",&m);
    int e[n],a[n],mat_alloc[m][n],mat_need[m][n];
    printf("Enter the total amount of each resources");
    for(i=0;i<n;i++){
        scanf("%d",&e[i]);}
    printf("Enter the available amount of each resources");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);}
    printf("Enter the amount of resources allocated to each processor");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mat_alloc[i][j]);}}
    printf("Enter the amount of resources needed by each processor");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mat_need[i][j]);}}
    for(l=0;l<m;l++){
    for(i=0;i<m;i++){
        count=0;
        for(j=0;j<n;j++){
            if(mat_need[i][j]<=a[j])
                count++;}
        if(count==n)
        {
            for(k=0;k<n;k++)
            {
                a[k]=a[k]+mat_alloc[i][k];
                mat_need[i][k]=999;
            }
            count1++;
        }
    }}
    if(count1==m)
        printf("Deadlock is avoided\n");
    else
        printf("Deadlock cannot be avoided\n");
    return 0;
}

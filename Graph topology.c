#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n=0,i=0,j=0,c=0,r=0,m=0;
    printf("Enter the number of nodes in the graph ");
    scanf("%d",&n);
    int x[n],adjmat[n][n],t[n];
    char f;
    printf("Enter the values of the nodes \n");;
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
    for(i=0;i<n;i++){
            c=0;
        for(j=0;j<n;j++){
            if(i==j)
                 adjmat[i][j]=0;
            else if(j<i){
                 adjmat[i][j]=adjmat[j][i];
                 if(adjmat[i][j]==1)
                    c++;
                 }
            else{
                 printf("Node %d and %d are adjacent?(y/n): ",x[i],x[j]);
                 scanf(" %c",&f);
                 if(f=='Y'||f=='y'){
                     adjmat[i][j]=1;
                     c++;}
                 else
                     adjmat[i][j]=0;
            }}
            t[i]=c;
            }
    printf("\nThe adjacency matrix for the graph is \n");
    for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    printf("%d ",adjmat[i][j]);
                }
                printf("\n");}
    printf("The graph belongs to ");
    c=0;
    for(i=0;i<n;i++)
    {
        if(t[i]==2)
            r++;
        else if(t[i]==(n-1))
            m++;
        else if(t[i]==1)
            c++;
    }
    if(r==n)
        printf("Ring topology.");
    else if(m==n)
        printf("Mesh topology.");
    else if(m==1&&c==(n-1))
        printf("Star topology.");
    else
        printf(" none of the given topology.");
}

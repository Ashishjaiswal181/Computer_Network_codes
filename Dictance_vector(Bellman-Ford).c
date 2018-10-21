#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <math.h>
#define INFI 999
int main()
{
    printf("Distance Vector Algorithm:\n");
    int s;
    printf("Enter the number of nodes. \n");
    scanf("%d",&s);
    int i,d[s][s],j;
    printf("Remember that the graph should not have a negative cycle\n");
    printf("Enter the adjacency matrix for the graph \n");
    for(i=0;i<s;i++){
        for(j=0;j<s;j++){
            scanf("%d",&d[i][j]);
        if(d[i][j]==0)
            d[i][j]=INFI;}
    }
    printf("Assuming the topology remains the same throughout and there ");
    printf("is no change in the cost \n");
    int k,hop[s][s];
    for(k=0;k<s;k++){
        for(i=0;i<s;i++){
            hop[k][i]=k+1;
            for(j=0;j<s;j++){
                if(k==i)
                    d[k][i]=0;
                else if(d[k][i]>(d[k][j]+d[j][i])){
                    if(d[k][j]==INFI||d[j][i]==INFI)
                        hop[k][i]=k+1;
                    else{
                        hop[k][i]=j+1;
                        d[k][i]=d[k][j]+d[j][i];}
    }}}}
    // rotate(s,d);}
    for(k=0;k<s;k++){
        printf("\nThe routing table for node %d  \n",k+1);
        for(i=0;i<s;i++){
            if(d[k][i]==INFI)
                printf("%d node not reachable.\n",i+1);
            else if(k==i)
                printf("");
            else
            printf("To %d  Cost %d  Next hop  %d \n",i+1,d[k][i],hop[k][i]);
        }printf("\n");}
    printf("Bellman-ford Algorithm shortest path\n");
    for(i=0;i<s;i++){
        for(j=0;j<s;j++){
            printf("%d ",d[i][j]);}
        printf("\n");}
    return 0;
}
/*int rotate(int s,int d[s][s])
{
    int temp[s],i,j;
    for(i=0;i<s;i++)
        temp[i]=d[0][i];
    for(i=0;i<s-1;i++){
        if(i<s-1)
            d[i][s-1]=d[i+1][0];
        for(j=0;j<s-1;j++)
            d[i][j]=d[i+1][j+1];}
    for(i=0;i<s;i++){
        d[s-1][i]=temp[i+1];
        d[s-1][s-1]=temp[0];}
    return d;
}
*/


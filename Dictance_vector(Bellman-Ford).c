#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <math.h>
//#define max 100
#define INFI 999
/*struct nodes{
    int x[max],y[max];
}n;*/
int main()
{
    int s;
    printf("Enter the number of nodes. \n");
    scanf("%d",&s);
    int i,d[s][s],j;
    /*FILE *f=fopen("Coordinates","w+");
    for(i=0;i<s;i++){
        n.x[i]=rand()%100+1;
        n.y[i]=rand()%50+1;}
    fclose(f);
    printf("The co-ordinate of the nodes: \n");
    for(i=0;i<s;i++){
        printf("%d is %d,%d \n",(i+1),n.x[i],n.y[i]);
    printf("The Distance/Adjacency matrix is :\n");
    for(i=0;i<s;i++){
        for(j=0;j<s;j++){
            if(i==j)
                d[i][j]=0;
            else{
                double ds=(pow((n.x[j]-n.x[i]),2)+pow((n.y[j]-n.y[i]),2));
                d[i][j]=sqrt(ds);}
            printf("%d ",d[i][j]);}
        printf("\n");}}*/
    printf("Enter the adjacency matrix for the graph \n");
    for(i=0;i<s;i++){
        for(j=0;j<s;j++){
            scanf("%d",&d[i][j]);
        if(i==j)
            d[i][j]=0;
        else if(d[i][j]==0)
            d[i][j]=INFI;}
    }
    /*for(i=0;i<s;i++)
    {
        for(j=0;j<s;j++)
            printf("%d ",d[i][j]);
        printf("\n");

    }*/
    printf("Since the weight of the nodes are generated randomly using positive ");
    printf("values only so there are no negative weight of negative cycle \n");
    printf("Assuming the topology remains the same throughout and there is no change in the cost \n");
    int k;
    for(k=0;k<s;k++){
        for(i=k+1;i<s;i++){
            for(j=0;j<=i;j++){
                if(k==j)
                    d[k][j]=0;
                else if(j<k)
                    d[k][j]=d[j][k];
                else if(d[k][j]>(d[k][j-1]+d[j-1][j]))
                    d[k][j]=d[k][j-1]+d[j-1][j];
            }
        }
    }
    for(i=0;i<s;i++){
        for(j=0;j<s;j++){
            printf("%d ",d[i][j]);}
        printf("\n");}


    return 0;
}

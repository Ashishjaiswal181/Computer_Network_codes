#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,count=0;
    //The data variables are declared and then the values are taken from the user.
    int data1[9],data2[9],data3[9],data4[9],data5[9],data6[9];
    printf("Enter the 5 data Bytes \n");
    printf("Enter the first data byte\n");
    for(i=0;i<8;i++)
        scanf("%d",&data1[i]);
    printf("Enter the second data byte\n");
    for(i=0;i<8;i++)
        scanf("%d",&data2[i]);
    printf("Enter the third data byte\n");
    for(i=0;i<8;i++)
        scanf("%d",&data3[i]);
    printf("Enter the fourth data byte\n");
    for(i=0;i<8;i++)
        scanf("%d",&data4[i]);
    printf("Enter the fifth data byte\n");
    for(i=0;i<8;i++)
        scanf("%d",&data5[i]);
    printf("Parity value '0' means even parity \n");
    printf("Parity value '1' means odd parity \n");
    data1[8]=check_1Dparity(data1);
    printf("1D parity of data1 is %d \n",data1[8]);
    data2[8]=check_1Dparity(data2);
    printf("1D parity of data2 is %d \n",data2[8]);
    data3[8]=check_1Dparity(data3);
    printf("1D parity of data3 is %d \n",data3[8]);
    data4[8]=check_1Dparity(data4);
    printf("1D parity of data4 is %d \n",data4[8]);
    data5[8]=check_1Dparity(data5);
    printf("1D parity of data5 is %d \n",data5[8]);
    //The following array of array makes the it easy to handle the 2D data.
    int parity_array[6]={data1,data2,data3,data4,data5,data6};
    for(i=0;i<9;i++)
    {
        count=0;
        for(j=0;j<5;j++)
        {
            //Pointer is used to access the values in the array inside the array.
           int *x=parity_array[j];//TO accept the same column values of each data using pointer
           if(x[i]==1)
                count++;
        }
        if(count%2==0)//To check for even parity.
            data6[i]=0;
        else//Else its an odd parity.
            data6[i]=1;
    }
    printf("2D parity of the 5 bytes of data is \n");
    for(i=0;i<9;i++)
        printf("%d ",data6[i]);
    return 0;
}
//The following function is called to check the parity of the given data.
int check_1Dparity(int a[])
{
    int i,count=0;
    for(i=0;i<8;i++)
      {
          if(a[i]==1){
            count++;}}//Counts the number of 1s in the data bits.
    if(count%2==0)//To check for even parity
        a[i]=0;
    else//Else its an odd parity
        a[i]=1;
    int z=a[i];
    return z;
}

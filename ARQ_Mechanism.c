#include <stdio.h>
#include <stdlib.h>
//#include <protocol.h>
int Frame()
{
    int frame[7],i;
    for(i=0;i<7;i++)
        frame[i]=rand()%2;
    return frame;
}

void Stopnwait()
{
    printf("Stop and wait mechanism execution\n");
    int i,success=1;
    for(i=0;i<20;i++)
    {
        success=0;
        success=senderSW();
        if(success==1)
            printf("Frame %d has been send successfully\n",i+1);
        else
            printf("Frame %d has failed to send, max try exhausted.\n",i+1);
    }
}

int senderSW()
{
    int buffer[7],ack,i,max_try=2;
    buffer[0]=Frame();
    ack=receiverSW(buffer);
    for(i=0;i<max_try;i++){
        if(ack!=1){
            printf("Resending frame \n");
            ack=receiverSW(buffer);}
        else
            return 1;
    }
    if(i==max_try)
        return 0;
}

int receiverSW(int frames[])
{
    return (rand()%2);
}

void Gobackn()
{
    senderGbn();
}

int senderGbn()
{
    int buffer[25],ack[25],i,max_try=2,j,temp_ack[5];
    ack[0]=resend();
    for(i=0;i<20;i++){
        for(j=0;j<max_try;j++){
            if(ack[i]!=1){
                printf("Resending frames \n");
                 ack[i]=resend();
                 }
             else{
                    printf("Frame %d sent successfully\n",i+1);
                    buffer[i+5]=Frame();
                    ack[i+5]=receiverGbn(buffer);
                    break;}
                }
        if(j==max_try){
            printf("Frame %d failed to send\n",i+1);
            buffer[i+5]=Frame();
            ack[i+5]=receiverGbn(buffer);}
        }
}

int resend()
{
    int i,buffer[5],ack[5];
    for(i=0;i<5;i++)
    {
        buffer[i]=Frame();
        ack[i]=receiverGbn(buffer[i]);
    }
    return ack;
}

int receiverGbn(int frames[])
{
    return (rand()%2);
}

void SelectiveRepeat()
{
    senderSR();
}

int senderSR()
{
    int buffer[25],ack[25],i,max_try=2,j;
    ack[0]=resend();
    for(i=0;i<20;i++){
        for(j=0;j<max_try;j++){
            if(ack[i]!=1){
                printf("Resending frame %d\n",i+1);
                if(i<5){
                    buffer[i]=Frame();
                    ack[i]=receiverSR(buffer);}
                else{
                    buffer[i+5]=Frame();
                    ack[i+5]=receiverSR(buffer);
                 }}
             else{
                    printf("Frame %d sent successfully\n",i+1);
                    buffer[i+5]=Frame();
                    ack[i+5]=receiverSR(buffer);
                    break;}
                }
        if(j==max_try){
            printf("Frame %d failed to send\n",i+1);
            buffer[i+5]=Frame();
            ack[i+5]=receiverSR(buffer);
        }}
}

int receiverSR(int frames[])
{
    int x=rand()%2;
    if(x==1)
        return 1;
    else
        return 0;
}

int main()
{
    int choice;
    srand(time(0));
    printf("Enter the ARQ mechanism you want to use.\n");
    printf("1. Stop-and-wait\n");
    printf("2. Go back N\n");
    printf("3. Selective repeat\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:Stopnwait();
                break;
        case 2:Gobackn();
                break;
        case 3:SelectiveRepeat();
                break;
        default:printf("Wrong choice\n");
    }
    return 0;
}

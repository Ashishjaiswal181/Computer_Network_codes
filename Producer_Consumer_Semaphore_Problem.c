/*
 * File:   main.c
 * Author: ASHISH JAIs
 *
 * Created on December 2, 2018, 1:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <windows.h>
#define N 10

sem_t empty,full,mutex;
/*
 *
 */
int buff[N],smth,count=0,sum;
int produce_item(){
    smth=rand()%100+1;
    printf("%d\n",smth);
    count++;
    return(smth);
}

int insert_item(int item){
    buff[count]=item;
    printf("Item inserted is %d\n",buff[count]);
}

int consume_item(int item){
    sum+=item;
    printf("Item consumed\nSum for now is %d\n",sum);
    if(sum>=100){
        printf("The program terminated when items consumed is more than 100\n");
        exit(0);}
}

int remove_item(){
    printf("Item removed is %d\n",smth);
    buff[count]=0;
    count--;
    return smth;
}

void *producer(void){
    int item;
    srand(time(0));
    while(1){
        item=produce_item();
        sem_wait(&empty);
        sem_wait(&mutex);
        insert_item(item);
        sem_post(&mutex);
        sem_post(&full);
        Sleep(1000);
    }
    return;
}

void *consumer(void){
    int item;
    while(1){
        sem_wait(&full);
        sem_wait(&mutex);
        item=remove_item();
        sem_post(&mutex);
        sem_post(&empty);
        consume_item(item);
    }
    return;
}

int main(int argc, char** argv) {
    sem_init(&empty,0,N);
    sem_init(&full,0,0);
    sem_init(&mutex,0,1);

    int status1,status2,sum=0;
    pthread_t thrd1,thrd2;
    status1=pthread_create(&thrd1,NULL,producer,NULL);
    status2=pthread_create(&thrd2,NULL,consumer,NULL);
    pthread_join(thrd1,NULL);
    pthread_join(thrd2,NULL);
    if(status1||status2){
        printf("Thread Error\n");
        exit(-1);
    }
    return (EXIT_SUCCESS);
}

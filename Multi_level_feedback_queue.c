#include<stdio.h>
int queue[1000];
int front = -1;
int rear = -1;
int sameArrival[10];
int visited[10] = {0};
int uniqueCount = 0;

void insertToQueue(int pid){
    if(front==-1 && rear == -1){
        front++;
        rear++;
        queue[rear] = pid;
        return;
    }
    rear++;
    queue[rear] = pid;
}

int isQueueEmpty(){
    if(front==-1 && rear == -1){
        return 1;
    }
    return 0;
}

void deleteFromQueue(){
    if(front==-1 && rear == -1){
        printf("Empty queue");
        return;
    }
    int ele = queue[front];
    if(front == rear) {
        front = -1;
        rear = -1;
        printf("P %d removed ",ele);
        printf("Queue is empty now");
        return;
    }
    front++;
    printf("P %d removed ",ele);

}

int exists(int val,int queue[]){
        for(int i=front;i<=rear;i++){
            if(queue[i]==val){
                return 1;
            }
        }
        return 0;
    }

int smallestInArrival(int arrival[]){
    int n=0;
    int small = 69696969;
    for(int i=0;i<=9;i++){
        if(arrival[i]<small){
            small = arrival[i];
        }
    }
    //now check is that if that arrival time is duplicate or not
    for(int i=0;i<=9;i++){
        if(arrival[i]==small){
            n++; // n is how many are same arrival times
        }
    }
    int j=0;
    for(int i=0;i<=9;i++){
        if(arrival[i]==small){
        sameArrival[j] = i;
        j++;
        }
    }
    return n;
}

void insertArrivedProcesses(int arrival[], int currentTime){
    for(int i=0;i<=9;i++){
        if(arrival[i] <= currentTime && visited[i] == 0){
            insertToQueue(i);
            visited[i] = 1;
        }
    }
}
int main(){

    int process[10] = {0,1,2,3,4,5,6,7,8,9};
    int arrival[10] = {0,0,0,1,1,1,2,2,3,4};
    int burst[10] = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
    int genntChart[100];

    // insert into ready queue
    int n = smallestInArrival(arrival);
    int currentTime = 0;
    for(int i=0;i<n;i++){
        insertToQueue(sameArrival[i]);
        visited[sameArrival[i]] = 1;
    }
    int stTime[100];
    int tq = 2;
    int genttChart[100];

//     int ft = queue[front];
// genttChart[0] = ft;
// stTime[0] = currentTime;
// deleteFromQueue();
// currentTime += tq;
// insertArrivedProcesses(arrival,currentTime);
// if(burst[ft] - tq > 0){
//     burst[ft] = burst[ft] - tq;
//     insertToQueue(ft);
int k=0;
    // LEVEL 1
int levelVisited[10] = {0};
for(int i=0; i<10; i++){
    int ft = queue[front];
    deleteFromQueue();
    genttChart[k] = ft;
    stTime[k] = currentTime;
    int remainder = burst[ft] - tq;
    if(remainder > 0){
        burst[ft] = remainder;
        currentTime = currentTime + tq;
        insertArrivedProcesses(arrival,currentTime);
        insertToQueue(ft);
    }
    else{
        currentTime = currentTime + burst[ft];
        burst[ft] = 0;
    }
    k++;
}

    return 0;
}
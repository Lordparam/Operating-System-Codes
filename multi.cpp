#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

int findMinimumInArrival(vector<int> arrival,vector<int> &sameArrival,unordered_map<int,bool> &visited){
    int min=INT_MAX;
    int count=0;
    for(int i=0;i<arrival.size();i++){
        if(arrival[i]<min){
            min=arrival[i];
        }
    }
    //same arrival time
    for(int i=0;i<arrival.size();i++){
        if(min==arrival[i]){
            sameArrival.push_back(i);
            count++;
        }
    }
    return count;
}

int main(){

    vector<int> process={0,1,2,3,4,5,6,7,8,9};
    vector<int> arrival={0,0,0,0,0,0,0,0,0,0};
    vector<int> burst={1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
    vector<int> remaining=burst;

    unordered_map<int,bool> visited;
    vector<int> queue;

    int currentTime=0;
    int tq=2;

    vector<int> sameArrival;

    int n=findMinimumInArrival(arrival,sameArrival,visited);

    //insert into queue
    for(int i=0;i<n;i++){
        queue.push_back(sameArrival[i]);
        visited[sameArrival[i]]=true;
    }

    // LEVEL 1 TO LEVEL 9
    for(int level=1;level<=9;level++){

        vector<int> nextQueue;
        int size=queue.size();
        cout<<"\nLEVEL "<<level<<"  TQ = "<<tq<<endl;

        for(int i=0;i<size;i++){
            int ft=queue.front();
            queue.erase(queue.begin());
            int execute=tq;
            if(remaining[ft]<tq){
                execute=remaining[ft]; // if remaining time quanta is less than tq
            }
            cout<<"P"<<ft<<" : "
                <<currentTime<<" - "
                <<currentTime+execute<<endl;
            currentTime=currentTime+execute;
            remaining[ft]=remaining[ft]-execute;
            if(remaining[ft]>0){
                nextQueue.push_back(ft);
            }
        }
        queue=nextQueue;
        tq=tq*2;
    }
    //FCFS now
    while(queue.size()!=0){
    int ft=queue.front();
    queue.erase(queue.begin());
    cout<<"P"<<ft<<" : "
        <<currentTime<<" - "
        <<currentTime+remaining[ft]<<endl;
    currentTime=currentTime+remaining[ft];
    remaining[ft]=0;
}

    return 0;
}
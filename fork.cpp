#include<iostream>
#include<unistd.h>
using namespace std;
int main(){
    // pid_t pid= fork();
    // if(pid<0){
    //     cout << "Fork Failed";
    //     return -1;
    // }
    // else if(pid==0){
    //     cout << "CHILD PROCESS" << endl;
    //     cout << "Child PID : " << getpid() << endl;
    //     cout << "Parent PID : " << getppid() << endl; 
    // }
    // else{
    //     cout << "PARENT PROCESS " << endl;
    //     cout << "Parent PID : " << getpid() << endl;
    //     cout << "Parent's Parent PID" << getppid() << endl;
    // }
    fork();
    cout << "a" << endl;
    fork();
    cout << "b" << endl;
    fork();
    cout << "c" << endl;
    return 0;
}
#include<iostream>
using namespace std;
#define maxSize 10

int Queue[maxSize];
int front =0,rear=-1;


void insertData(int pos, int data){  //enqueue
    if(rear==maxSize-1){
        cout<<"Queue overflow!!!"<<endl;
    }
    else{
            rear+=1;
            Queue[rear]=data;
        }
}


void deleteData(){  //dequeue
    if(front>rear){
        cout<<"Queue underflow!!!"<<endl;
        return;
}
    else{
        cout<<"Element deleted from queue :"<<Queue[front]<<endl;
        front+=1;
    }
    
}

void printQueueStatus(){
    for(int i=front;i<=rear;i++){
        cout<<Queue[i]<<" ";
    }
    cout<<endl;
}

int main(){
    
    return 0;
}
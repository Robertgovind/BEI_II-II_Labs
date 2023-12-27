#include<iostream>
using namespace std;
#define maxSize 5

int Queue[maxSize];
int front =0,rear=-1;

void Enqueue(int data){  //enqueue
    if(rear==maxSize-1){
        cout<<"Queue overflow!!!"<<endl;
    }
    else{
            rear+=1;
            Queue[rear]=data;
        }
        }


void Dequeue(){  //dequeue
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
    Dequeue();
    Enqueue(4);
    Dequeue();
    // Enqueue(5);
    // Enqueue(4);
    // Enqueue(9);
    // Enqueue(8);
    // Enqueue(2);
    // printQueueStatus();
    // Dequeue();
    // printQueueStatus();
    return 0;
}
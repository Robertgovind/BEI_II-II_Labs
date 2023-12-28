#include<iostream>
using namespace std;
#define maxSize 5

int Queue[maxSize];
int front =-1,rear=-1;

void Enqueue(int data){  //enqueue
    if((front==0 && rear==maxSize-1)||front==rear+1){
        cout<<"Queue overflow!!!"<<endl;
    }
    else{
            if(front==-1){
                front=rear=0;
            }
            else{
                rear=(rear+1)%maxSize;
            }
            Queue[rear]=data;
        }
     }
        

void Dequeue(){  //dequeue
    if(front==-1){
        cout<<"Queue underflow!!!"<<endl;
        return;
    }
    else{
        if(front==rear){
            front=rear=-1;
        }else{
         cout<<"Element deleted from queue :"<<Queue[front]<<endl;
         front=(front+1)%maxSize;   
        }
    }
    
}

void printQueueStatus(){
    
    for(int i=front;i<=rear;i++){
        cout<<Queue[i]<<" ";
    }
    int i=front;
    if(front>rear){
    do{
        cout<<Queue[i]<<" ";
        i=(i+1)%maxSize;
    }while(i!=front);
    }
    cout<<endl;
    cout<<"Front : "<<front<<"  Rear : "<<rear<<endl;
}

int main(){
   
    Enqueue(5);
    Enqueue(2);
    printQueueStatus();
    Dequeue();
    printQueueStatus();
    Enqueue(5);
    printQueueStatus();
    Enqueue(8);
    printQueueStatus();
    Enqueue(3);
    printQueueStatus();
    Enqueue(1);
    printQueueStatus();

    
    //printQueueStatus();
    return 0;
}
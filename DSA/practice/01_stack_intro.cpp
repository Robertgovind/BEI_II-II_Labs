#include<iostream>
using namespace std;
void push(int* tos,int max,int items[]){
    if(*tos==max){
        cout<<"Stack is full";
        return;
    }
    else if(*tos==-1){
        *tos=0;
    }
    else{
        *tos++;
    }
    int data;
    cout<<"Enter data : ";
    cin>>data;
    items[*tos]=data;
    cout<<endl;
}

int main(){
    int tos=-1,stackSize=5,items[stackSize];
    for(int i=0;i<stackSize;i++){
        push(&tos,stackSize,items);
    }
    cout<<items[3];
}
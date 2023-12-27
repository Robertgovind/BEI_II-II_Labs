#include<iostream>
using namespace std;
#define stackSize 5

int stack[stackSize];
int tos=-1;

void push(int item){
    if(tos==stackSize-1){
        cout<<"Stack overflow!!"<<endl;
    }
    else{
        tos+=1;
        stack[tos]=item;
    }
}

void pop(){
    if(tos==-1){
        cout<<"Stack Underflow!!!"<<endl;
    }
    else{
        cout<<"Poped :"<<stack[tos]<<endl;
        tos-=1;
    }
}

void printStackStatus(){
    for(int i=tos;i>=0;i--){
        cout<<stack[i]<<endl;
    }
}

int main(){
    push(5);
    push(6);
    printStackStatus();
    pop();
    printStackStatus    ();
    return 0;
}
#include<iostream>
using namespace std;
#define max  5

int stack[max];
int tos=-1;

void push(int item){
    int i;
    tos+=1;
    cout<<tos<<endl;
    cout<<"Push ="<<item<<endl;
    for(i=tos;i>0;i--){
        stack[i]=stack[i-1];
    }
    stack[0]=item;
} 

int pop(){
    int i,data;
    data=stack[0];
    for(i=0;i<tos;i++){
        stack[0]=stack[i+1];
        tos-=1;
    }
    return data;
}

void print(){
    int i;
    if(tos==-1){
        cout<<"Stack underflow"<<endl;
        exit(1);
    }
    else{
        cout<<"After pop :"<<endl;
        for(i=0;i<=tos;i++){
            cout<<stack[i]<<endl;
        }
    }
}

int main(){
    push(5);
    push(3);
    cout<<stack[1];
   cout<<stack[0];
   int data=pop();
   cout<<data;
    return 0;
}
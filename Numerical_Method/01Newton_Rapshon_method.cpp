#include<iostream>
#include<math.h>
using namespace std;

float fun(float x){
    return x*x*x-4*x-9;
}

float dfun(float x){
    return 3*x*x-4;
}
int main(){
    //Input : 2 0.0001
    //Ans : 2.70653
    int iterations=1;
    float x0,e,x1;
    cout<<"Enter x0 and stopping condition : "<<endl;
    cin>>x0>>e;
    do{
        x1=x0-fun(x0)/dfun(x0);
        cout<<"Iteration  "<<iterations<<"  "<<"x0 = "<<x0<<endl;
        x0=x1;
        iterations++;
    }while(iterations<=15);

    cout<<"Root = "<<x0;
    return 0;
}
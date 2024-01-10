//RK 1nd order method
#include<iostream>
#include<iostream>
using namespace std;

float F(float x,float y){
    return (3*x*x+1);
}

int main(){
    float x0,y0,h,xnew,ynew,x;
    cout<<"Enter x0 and y0 and h :"<<endl;
    cin>>x0>>y0>>h;
    cout<<"Enter the val of x"<<endl;
    cin>>x;
    xnew=x0,ynew=y0;
    int count=1;
    while(xnew<x){
        ynew=ynew+h*F(xnew,ynew);
        xnew=xnew+h;
        cout<<"Iteration "<<count<<" xnew = "<<xnew<< " ynew = "<<ynew<<endl;
        count++;
    }
    cout<<"The actual answer is : "<< ynew<<endl;
    return 0;
}
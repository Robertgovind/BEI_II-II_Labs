#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double F(double x,double y){
    return (x+pow(y,0.5));
}

int main(){
    double x0,y0,x,y,h,xn,m1,m2;
    cout<<"Enter x0, y0, h, xn :"<<endl;
    cin>>x0>>y0>>h>>xn;
    x=x0,y=y0;
    while(x!=xn){
        m1=F(x,y);
        x=x+h;
        m2=F(x,y+h*m1);
        y=y+h*(m1+m2)/2;
    }
    cout<<y<<endl;
    return 0;
}
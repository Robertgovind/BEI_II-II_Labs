#include<iostream>
#include<bits/stdc++.h>
using namespace std;

float F(float x,float y){
    return ((y*y-x*x)/(y*y+x*x));
}
int main(){
    double x0,y0,x,y,m1,m2,m3,m4,h,xn;
    cout<<"Enter the values x0, y0, xn, h :"<<endl;
    cin>>x0>>y0>>xn>>h;
    x=x0,y=y0;
    while(x!=xn){
        m1=F(x,y);
        m2=F(x+h*0.5,y+m1*h*0.5);
        m3=F(x+h*0.5,y+m2*h*0.5);
        m4=F(x+h,y+m3*h);
        y=y+(h*(m1+2*(m2+m3)+m4))/6;
        x=x+h;
        cout<<"At x "<<x<<" y "<<y<<endl;
    }
    cout<<y;
    return 0;
}
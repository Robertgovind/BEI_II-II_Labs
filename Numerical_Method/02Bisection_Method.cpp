#include<iostream>
#include<math.h>
using namespace std;

float fun(float x){
    return x*x*x-4*x-9;
}

int main(){
    //Input : 1 3 0.0001
    //Root : 2.70648
    int iterations=1;
    float x0,x1,x2,e,f0,f1;
    cout<<"Enter initial guess x0, x1 and e : "<<endl;
    cin>>x0>>x1>>e;
    if(fun(x0)*fun(x1)<0){
        do{
        x2=(x0+x1)/2;
        if(fun(x0)*fun(x2)<0){
            x1=x2;
            f1=fun(x2);
        }
        else{
            x0=x2;
            f0=fun(x2);
        }
        cout<<"Iteration : "<<iterations<<"  "<<x2<<endl;
        iterations++;
          }while(fabs(x0-x1)>e);
    }else{
        cout<<"Wrong guess.";
    }
    cout<<"Root : "<<x2;
    return 0;
}
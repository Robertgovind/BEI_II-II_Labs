#include<iostream>
#include<math.h>
using namespace std;
float fun(float x){
    //  return x*x*x-3*x*x+x+1;
    //  return (sin(x)-2*x+1);
    return 3*x-cos(x)-1;
    // return x*x*x-4*x-9;
 }

int main(){
    float x0,x1,x2,e;
    cout<<"Enter x0, x1 and e : "<<endl;
    cin>>x0>>x1>>e;

    do{
        x2=(fun(x1)*x0-fun(x0)*x1)/(fun(x1)-fun(x0));
        x0=x1;
        x1=x2;
    }while(fabs(x1-x0)>e);

    cout<<"Root = "<<x2<<endl;
    return 0;

}
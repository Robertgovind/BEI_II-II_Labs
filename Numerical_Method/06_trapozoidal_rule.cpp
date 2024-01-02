#include<iostream>
#include<math.h>
using namespace std;

float y(float x){
    return exp(x);
}

int main(){
    float a,b,h,s;
    int i,n;
    cout<<"Enter a,b, no of subinterbals : "<<endl;
    cin>>a>>b>>n;
    h=(b-a)/n;
    s=y(a)+y(b);
    for(int i=1;i<=n-1;i++){
        s+=2*y(a+i*h);
    }

    cout<<"Value of Integral is :"<<s*(h/2)<<endl;
    return 0;
}
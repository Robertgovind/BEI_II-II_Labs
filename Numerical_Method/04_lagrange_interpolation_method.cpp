#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of data :"<<endl;
    cin>>n;
    float x[n],f[n];
    for(int i=0;i<n;i++){
        cout<<"Enter x"<<i<<endl;
        cin>>x[i];
        cout<<"Enter f"<<i<<endl;
        cin>>f[i];
    }
    float y;
    cout<<"Enter the value of x to find p(x): "<<endl;
    cin>>y;
    float finalSum;
    for(int i=0;i<n;i++){
        float xi=x[i],fi=f[i],num=1,dnum=1;
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            else{
                num*=(y-x[j]);
                dnum*=(xi-x[j]);
            }
        }
        num*=fi;
        finalSum+=(num)/dnum;
    }
    cout<<"Final value : "<<finalSum<<endl;
}
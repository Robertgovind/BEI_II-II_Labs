#include<iostream>
using namespace std;

void towerOfHannoi(string src, string dest, string aux, int n){
    if(n==0)
    return ;

    towerOfHannoi(src,aux,dest,n-1);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerOfHannoi(aux,dest,src,n-1);

}

int main(){
    towerOfHannoi("L","R","C",3);
    return 0;
}
#include<iostream>
using namespace std;
#define listSize 10

int list[listSize]={-1},n;
 void create(int n){
    if(n<listSize){
        for(int i=0;i<n;i++){
            int data;
            cin>>data;
            list[i]=data;
        }
    }
    else{
        cout<<"Cannot be created"<<endl;
    }
 }

 void insertData(int pos,int data){
    if(pos>=n){
        cout<<"Cannot add data."<<endl;
    }
    for(int i=n-1;i>=pos;i--){
        list[i+1]=list[i];
    }
    list[pos]=data;
    n+=1;
 }

 void deleteData(int pos){
    if(pos>=n){
        cout<<"Cannot delete data!"<<endl;
    }
    for(int i=pos;i<n-1;i++){
        list[i]=list[i+1];
    }
    n-=1;
 }

 bool searchData(int data){
    for(int i=0;i<n;i++){
        if(data==list[i])
        return true;
    }
    return false;
 }

 void printList(){
    for(int i=0;i<n;i++){
        cout<<list[i]<<" ";
    }
    cout<<endl;
 }

int main(){
    n=5;
    create(n);
    printList();
    insertData(0,10);
    printList();
    deleteData(4);
    printList();
    cout<<"Search for data 2 "<<searchData(2)<<endl;
    return 0;
}
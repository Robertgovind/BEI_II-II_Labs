#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[],int n){
    
    for(int i=0;i<n-1;i++){
        bool alreadySorted=true;
        cout<<"Iteration "<<i+1<<endl;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                alreadySorted=false;
            }
            printArray(arr,5);      
        }
        //optimized code for already sorted
         if(alreadySorted){
            return ; 
            }
    }
}

int main(){
    int arr[5]={4,9,2,6,8};
    printArray(arr,5);
    bubbleSort(arr,5);
    printArray(arr,5);
    return 0;
}
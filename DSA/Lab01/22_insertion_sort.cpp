#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int j;
        int temp=arr[i];
    for(j=i-1;j>=0;j--){
        if(arr[j]>temp){
            arr[j+1]=arr[j];
        }
        else{
            break;
        }
    }
    arr[j+1]=temp;
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[5]={4,3,2,6,8};
    printArray(arr,5);
    insertionSort(arr,5);
    printArray(arr,5)   ;
}
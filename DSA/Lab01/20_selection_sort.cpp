#include<iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[minIndex]>arr[j])
            minIndex=j;
        }
        swap(arr[minIndex],arr[i]);
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[6]={2,6,3,4,8,9};
    printArray(arr,6);
    selectionSort(arr,6);
    printArray(arr,6);
    return 0;
}
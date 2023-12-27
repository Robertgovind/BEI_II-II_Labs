#include<iostream>
#include<math.h>
using namespace std;

void printAugMatrix(float arr[][5],int n,int m){
    cout<<"Printing augmented matrix :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void makeUpperTriangle(float arr[][5],int n,int m){
    int i,j,k;
    float factor;
    for( i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            factor=arr[j][i]/arr[i][i];
            for(k=0;k<m;k++){
                arr[j][k]=arr[j][k]-(arr[i][k]*factor);
                if(fabs(arr[j][k])<0.0001)
                arr[j][k]=0;
            }
        }
    }
}

void backSubstitution(float arr[][5],int n,int m,float x[]){
    float s;
    int i,j;
    for(i=n-1;i>=0;i--){
        s=0;
        for(j=i+1;j<n;j++){
            s=s+arr[i][j]*x[j]; 
        }
         x[i]=(arr[i][n]-s)/arr[i][i];
    }

    cout<<"Printing Solution "<<endl;
    for(i=0;i<n;i++){
        cout<<"x"<<i+1<<" = "<<x[i]<<endl;
    }
}
int main(){
    float x[4]  ;
    float mat[4][5]={
        {10,-7,3,5,6},
        {-6,8,-1,-4,5},
        {3,1,4,11,2},
        {5,-9,-2,4,7}};
    printAugMatrix(mat,4,5);
    makeUpperTriangle(mat,4,5);
    printAugMatrix(mat,4,5);
    backSubstitution(mat,4,5,x);
    return 0;
} 
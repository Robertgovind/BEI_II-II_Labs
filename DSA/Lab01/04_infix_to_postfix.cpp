#include<iostream>
using namespace std;

int Precedence(char ch){
    if(ch=='^'){
        return 2;
    }
    else if(ch=='*'|| ch=='/'){
        return 1;
    }
    else{
        return 0;
    }
}
void convert(char infix[],char postfix[]){

}
int main(){
    char infix[25];
    char postfix[25];
    cout<<"Enter infix expression :"<<endl;
    cin>>infix;
    cout<<infix<<endl;
    cout<<Precedence('-');

    convert(infix,postfix);
    return 0;
}
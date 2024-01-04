#include<iostream>
using namespace std;
#define stackSize 25

char stack[stackSize];

int tos=-1;

int Precedence(char ch){
    if(ch=='^' || ch=='$'){
        return 3;
    }
    else if(ch=='*'|| ch=='/' || ch=='%'){
        return 2;
    }
    else if(ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

void push(char item){
    if(tos==(stackSize-1)){
        cout<<"Stack overflow!!"<<endl;
    }
    else{
        tos+=1;
        stack[tos]=item;
    }
}

char pop(){
    char data;
    if(tos==-1){
        cout<<"Stack Underflow!!!"<<endl;
    }
    else{
        data=stack[tos];
        tos-=1;
    }
    return data;
}

void printStackStatus(){
    for(int i=tos;i>=0;i--){
        cout<<stack[i]<<" "<<endl;
    }
}

bool isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^' || ch=='(' || ch==')'){
        return true;
    }
    else{
        return false;
    }
}

void convert(string infix,string postfix){
    for(int i=0;i<infix.length();i++){
        char ch=infix[i];
        if(isOperator(ch)){
            if(ch=='('){
                push(ch);
            }
            else if(ch==')'){
                while(ch!='('){
                    postfix+=pop();
                }
                pop();
            }
            else{
                if(tos==-1){
                    push(ch);
                }
                else if(Precedence(stack[tos]>=Precedence(ch))){
                    postfix+=pop();
                    push(ch);
                }
                else{
                    push(ch);
                }
            }
        }
        else{
            postfix+=ch;
        }
     
    }
    while (tos!=-1){
        postfix+=pop();
       }
    cout<<postfix<<endl;

    
}
int main(){
    string infix;
    string postfix="";
    cout<<"Enter infix expression :"<<endl;
    cin>>infix;
    convert(infix,postfix);
    cout<<postfix;
    return 0;
}
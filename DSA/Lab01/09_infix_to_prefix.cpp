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
        return 0;
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
            else {
              if(ch==')'){
                while(stack[tos]!='('){
                    postfix+=pop();
                }
                pop();
               }
              else{
                if(Precedence(stack[tos]<Precedence(ch))){
                    push(ch);
                }
                else{
                    while (Precedence(stack[tos])>=Precedence(ch)){
                        postfix+=pop();
                    }
                    push(ch);
                }
              }
            }
        }
        else{
            postfix+=ch;
        }
    }
    while (stack[tos]!='&'){
        postfix+=pop();
       }
    cout<<postfix<<endl;

    
}

void reverseString(string str){
    int s=0,e=str.length()-1;
    while(s<=e){
        swap(str[s++],str[e--]);
    }
}
int main(){
    string infix;
    string postfix="";
    cout<<"Enter infix expression :"<<endl;
    cin>>infix;
    tos+=1;
    stack[tos]='&';
    reverseString(infix);
    convert(infix,postfix);
    reverseString(postfix);
    for(int i=postfix.length()-1;i>=1;i--)
    cout<<postfix[i];
    return 0;
}
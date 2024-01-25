#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* createTree(node* r){
    cout<<"Enter the data :"<<endl;
    int data;
    cin>>data;

    if(data == -5)  //Consider -5 as null
    return NULL;

    r=new node(data);


    cout<<"Enter data for left of "<<data<<endl;
    r->left = createTree(r->left);
    cout<<"Enter data for right of "<<data<<endl;
    r->right = createTree(r->right);

    return r;
}
void preOrderTraversal(){
    
}

void levelOrderTraversal(node* root){
    queue<node*> tree;
    tree.push(root);
    tree.push(NULL);

    while(!tree.empty()){
        node* temp = tree.front();
        tree.pop();

        if(temp == NULL){
            cout<<endl;
            if(!tree.empty()){
                tree.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
            tree.push(temp->left);
            if(temp->right)
            tree.push(temp->right);
        }
    }
}

int main(){
    node* root;

    //data : 3 5 12 -5 -5 13 -5 -5 7 18 -5 -5 24 -5 -5

    root = createTree(root);
    cout<<"Tree ir represented as :"<<endl;
    levelOrderTraversal(root);
    return 0;
}


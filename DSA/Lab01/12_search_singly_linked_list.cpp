#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int info;
    struct node *next;
};

struct node *ptr,*head;

void insertAtFirst(){
    struct node *item;
    item=(node*)malloc(sizeof(node));
    cout<<"Enter the data :" <<endl;
    cin>>item->info;
    if(head==NULL){
        item->next=NULL;
        head=item;
    }
    else{
        item->next=head;
        head=item;
    }
}

void insertAtEnd(){
    struct node *temp, *item;
    item=(node*)malloc(sizeof(node));
    cout<<"Enter the data :"<<endl;
    cin>>item->info;
    item->next=NULL;
    if(head==NULL){
        head=item;
    }
    else{
        temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=item;
    }

}
void insertAtPos(int pos){
    if(pos==0){
        insertAtFirst();
        return;
    }

    int count=1;
    struct node *temp,*item;
    item=(node*)malloc(sizeof(node));
    cout<<"Enter the data :"<<endl;
    cin>>item->info;
    temp=head;
    while(count<pos){
        temp=temp->next;
        if(temp->next == NULL){
            cout<<"Position not found!"<<endl;
            return;
        }
        count++;
    }
    item->next=temp->next;
    temp->next=item;
}

void printLinkedList(){
    struct node *temp;
    temp=head;
    while (temp!=NULL)
    {
        cout<<temp->info<<"---->";
        temp=temp->next;
    }
    cout<<endl;
}
bool searchLinkedLIst(int n){
    struct node *temp;
    temp=head;
    while (temp!=NULL)
    {
        if(temp->info ==n)
        return true;

        temp=temp->next;
    }
    return false;
}

int main(){
    //creating a first node
    head=NULL;
    insertAtFirst();
    insertAtFirst(); 
    insertAtFirst();
    printLinkedList();
    insertAtEnd(); // at end of linked list
    printLinkedList();
    insertAtPos(2);   //insert at pos 2
    printLinkedList();
    cout<<searchLinkedLIst(2);
    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int info;
    struct node *next;
};
struct node *ptr,*head,*last;

// INSERTION OPERATIONS
void insertAtFirst(){
    struct node *item;
    item=(node*)malloc(sizeof(node));
    cout<<"Enter the data :" <<endl;
    cin>>item->info;
    if(head==NULL){
        item->next=item;
        head=item;
        last=item;
    }
    else{
        item->next=head;
        head=item;
        last->next=item;
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
void insertAtEnd(){
    struct node *temp, *item;
    item=(node*)malloc(sizeof(node));
    cout<<"Enter the data :"<<endl;
    cin>>item->info;
    item->next=NULL;
    if(head==NULL){
        item->next=item;
        head=item;
        last=item;
    }
    else{
        last->next=item;
        last=item;
        last->next=head;
    }
}
//DELETION OPERATIONS
void deleteFromFirst(){
    struct node *temp;
    temp=head;
    if(head==NULL){
        cout<<"List underflow!"<<endl;
        return;
    }
    else if(temp->next == head){
        cout<<"Deleted :"<<head->info<<endl;
        free(temp);
        head==NULL;
        last=NULL;
    }
    else{
        head=head->next;
        cout<<"Deleted : "<<temp->info<<endl;
        last->next=head;
        free(temp);
    }
}
void deleteFromPosition(int pos){
    struct node *temp,*delLocation;
    if(head==NULL){
        cout<<"List underflow!"<<endl;
        return ;
    }
    else if (head->next == NULL){
        head=NULL;
        free(head);
    }
    else{
        if(pos==1)
        deleteFromFirst();
        else{
            int count=1;
            temp=head;
            while(count<pos){
                delLocation=temp;
                temp=temp->next;
                count++;
            }
            cout<<"Deleted :"<<temp->info<<endl;
            delLocation->next=NULL;
            free(temp);
        }
    }
}
void deleteFromLast(){
    struct node *temp,*delLocation;
    
    if(head == NULL){
        cout<<"List underflow!"<<endl;
        return;
    }
    else if(head->next == head){
        cout<<"Deleted :"<<head->info<<endl;
        head=NULL;
        free(head);
        head=NULL;
        last=NULL;
    }
    else{
        temp=head;
        while(temp->next!=head){
            delLocation=temp;
            temp=temp->next;
        }
        cout<<"Deleted :"<<temp->info<<endl;
        delLocation->next=temp->next;
        last=delLocation;
        free(temp);
    }
}
void printLinkedList(){
    struct node *temp;
    temp=head;
    do
    {
        cout<<temp->info<<"---->";
        temp=temp->next;
    }while (temp != head);
    cout<<endl;
}
int main(){
    //creating a first node
    head=NULL;
    last==NULL;
    insertAtFirst();
    printLinkedList();
    insertAtFirst();
    printLinkedList();
    insertAtFirst();
    printLinkedList();
    deleteFromFirst();
    deleteFromLast();
    return 0;
}
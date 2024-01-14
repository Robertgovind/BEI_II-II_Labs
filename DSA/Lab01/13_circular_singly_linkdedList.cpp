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

 //Traversing linked list
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
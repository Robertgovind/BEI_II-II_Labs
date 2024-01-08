#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int info;
    struct node *next;
};

struct node *ptr,*head;

// INSERTION OPERATIONS
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

//DELETION OPERATIONS
void deleteFromFirst(){
    struct node *temp;
    temp=head;
    if(head==NULL){
        cout<<"List underflow!"<<endl;
        return;
    }
    else if(temp->next == NULL){
        head=NULL;
        free(temp);
    }
    else{
        head=head->next;
        cout<<"Deleted : "<<temp->info<<endl;
        free(temp);
    }

}

void deleteFromLast(){
    struct node *temp,*delLocation;
    
    if(head == NULL){
        cout<<"List underflow!"<<endl;
        return;
    }
    else if(head->next == NULL){
        cout<<"Deleted :"<<head->info<<endl;
        head=NULL;
        free(head);
    }
    else{
        temp=head;
        while(temp->next != NULL){
            delLocation=temp;
            temp=temp->next;
        }
        delLocation->next=NULL;
        cout<<"Deleted :"<<temp->info<<endl;
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
 
 //Traversing linked list
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

int main(){
    //creating a first node
    head=NULL;
    insertAtFirst();
    printLinkedList();
    insertAtFirst();
    printLinkedList();
    insertAtFirst();
    printLinkedList();
    insertAtEnd(); // at end of linked list
    printLinkedList();
    insertAtPos(2);   //insert at pos 2
    printLinkedList();
    deleteFromFirst(); // delete from first 
    printLinkedList();
    deleteFromLast();  //delete from last
    printLinkedList();
    deleteFromPosition(2);
    printLinkedList();
    return 0;
}
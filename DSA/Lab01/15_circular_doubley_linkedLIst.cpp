#include<iostream>
using namespace std;

struct node{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *head, *last;

void insertAtFirst(){
    struct node* item;
    item=(node*)malloc(sizeof(node));
    cout<<"Enter the data :"<<endl;
    cin>>item->info;
    if(head==NULL){
        item->next=item;
        item->prev=item;
        head = item;
        last=item;
    }
    else{
        item->prev=head->prev;
        item->next=head;
        head->prev=item;
        last->next=item;
        head=item;
    }
}

void insertAtPos(int pos){
    if(pos==0){
        insertAtFirst();
        return;
    }
    struct node *temp,*item;
    item=(node*)malloc(sizeof(node));
    cout<<"Enter the data :"<<endl;
    cin>>item->info;
    temp=head;
    for(int i=0;i<=pos;i++){
        temp=temp->next;
        if(temp==NULL){
            cout<<"Position not found!!"<<endl;
            return;
        }
    }
    item->next=temp;
    item->prev=last;;
    temp->prev->next=item;
    temp->prev=item;

}
void insertAtEnd(){
    struct node* item,*temp;
    item=(node*)malloc(sizeof(node));
    cout<<"Enter the data :"<<endl;
    cin>>item->info;
    if(head==NULL){
        item->next=item;
        item->prev=item;
        head = item;
        last=item;
    }
    else{
        temp=head;
        while(temp->next != head){
            temp=temp->next;
        }
        temp->next=item;
        item->next=head;
        item->prev=temp;
    }
}

//Deletion 
void deleteFromFirst(){
    struct node* temp;
    temp=head;
    if(temp==NULL){
        cout<<"List is empty!!"<<endl;
        return;
    }
    else if(temp->next==head){
        head=NULL;
        last=NULL;
        cout<<"Deleted :"<<temp->info<<endl;
        free(temp);
    }
    else{
        head=head->next;
        cout<<"Deleted :"<<temp->info<<endl;
        head->prev=last;
        free(temp);
    }
}

void deleteFromPos(int pos){
    struct node* temp;
    temp=head;
    if(pos==0){
        deleteFromFirst();
        return;
    }
    else{
        for(int i=0;i<=pos;i++){
            temp=temp->next;
            if(temp==NULL){
                cout<<"Position not found!!"<<endl;
                return;
            }
        }
        cout<<"Deleted :"<<temp->info<<endl;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}
void deleteFromEnd(){
    struct node* temp;
    temp=head;
    if(head==NULL){
        cout<<"List is empty!!"<<endl;
        return ;
    }
    else if(temp->next==NULL){
        head=NULL;
        cout<<"Deleted :"<<temp->info<<endl;
        free(temp);
    }
    else{
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;//store null to next of prev of temp
        cout<<"Deleted :"<<temp->info<<endl;
        free(temp);
    }
}

void printLinkdedList(){
    struct node* temp;
    temp=(node*)malloc(sizeof(node));
    temp=head;
    while(temp !=NULL){
        cout<<temp->info<<"--->";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    head =NULL;
    insertAtFirst();
    insertAtFirst();
    insertAtEnd();
    insertAtEnd();
    printLinkdedList();
    insertAtPos(1);
    printLinkdedList();
    return 0;
}
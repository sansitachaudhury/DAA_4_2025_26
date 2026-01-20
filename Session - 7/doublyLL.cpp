#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;   
};

node* head = NULL;
void insert(int val){
    node* newnode = new node();
    newnode->data =val;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(!head){
        head=newnode;
        return;
    }
    node* curr=head;
    while(curr->next){
        curr=curr->next;
    }
    curr->next=newnode;
    newnode->prev=curr;
}
void del(int val){
    node* curr=head;
    while(curr!=NULL&&curr->data!=val){
        curr=curr->next;
    }
    if(curr==NULL)
        return;  

    if(curr->prev!=NULL){
        curr->prev->next=curr->next;
    }
    else{
        head=curr->next;  
    }
    if(curr->next!=NULL){
        curr->next->prev=curr->prev;
    }
    delete curr;
}
void display(){
    node* curr=head;
    while(curr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
int main(){
    insert(10);
    insert(20);
    insert(30);
    display(); 
    del(20);
    display();  
}

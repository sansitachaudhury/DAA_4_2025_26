//Question: implement queue using linked list
#include <iostream>
using namespace std;

class Node
{public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data =data;
        this->next =NULL;
    }
};

class Queue{
public:
    Node *front;
    Node *rear;

    Queue()
    {
        front = rear = NULL;
    }
    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (rear ==NULL)
        {
            front=rear=newNode;
            return;
        }
        rear->next=newNode;
        rear =newNode;
    }
    void dequeue()
    {
        if (front ==NULL)
            return;
        Node *temp =front;
        front =front->next;
        if (front==NULL)
            rear=NULL;
        delete temp;
    }
    int peek()
    {
        if (front==NULL)
            return -1; 
        return front->data;
    }
    int size()
    {
        int count=0;
        Node *temp=front;
        while (temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    bool isempty()
    {
        return front==NULL;
    }
    void display()
    {
        Node *temp=front;
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main(){
    Queue q;
    cout<<q.isempty()<<endl;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<"elements -> ";
    q.display();
    cout<<endl;
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    cout<<q.size()<<endl;

}
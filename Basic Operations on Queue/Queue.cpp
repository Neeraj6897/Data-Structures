#include<bits/stdc++.h>
using namespace std;

class static_queue{
    public:
    int qu[5];
    int front = -1;
    int rear = -1;
    
    void enqueue(int value){
        if(front<0){
            front++; rear++;
            qu[front] = value;
        }
        else{
            rear++;
            qu[rear] = value;
        }
    }
    
    void displayQueue(){
        if(front<0){
            cout<<"Empty queue"<<"\n";
        }
        else{
            for(int i=front;i<=rear;i++){
                cout<<qu[i]<<"\t";
            }
            cout<<"\n";
        }
    }
    
    void dequeue(){
        if(front<0){
            cout<<"Underflow condition"<<"\n";
        }
        else{
            cout<<"Deleting: "<<qu[front]<<"\n";
            front++;
        }
    }
};

class Node{
    public:
    int data;
    Node * next;
};

class dynamic_queue{
    private:
    Node * front;
    Node * rear;
    
    public:
    dynamic_queue(){
        front = NULL;
        rear = NULL;
    }
    
    void enqueue(int value){
        Node * temp = new Node;
        temp->data = value;
        temp->next = NULL;
        if(front==NULL){
            front = temp;
            rear = temp;
        }
        
        else{
            rear->next = temp;
            rear = temp;
        }
    }
    
    void displayQueue(){
        Node *temp;
        if(front == NULL){
            cout<<"Empty queue"<<"\n";
        }
        else{
            temp = front;
            while(temp != rear){
                cout<<temp->data<<"\t";
                temp = temp->next;
            }
            cout<<temp->data;
            cout<<"\n";
        }
    }
    
    void dequeue(){
        Node *temp;
        if(front == NULL){
            cout<<"Underflow condition"<<"\n";
        }
        else{
            temp = front;
            front = front->next;
            free(temp);
        }
    }
    
};

int main(){
    
    static_queue ele;
    ele.enqueue(5);
    ele.enqueue(6);
    ele.enqueue(7);
    ele.displayQueue();
    ele.dequeue();
    ele.displayQueue();

    dynamic_queue element;
    element.enqueue(5);
    element.enqueue(6);
    element.enqueue(7);
    element.displayQueue();
    element.dequeue();
    element.displayQueue();
    
    return 0;
}

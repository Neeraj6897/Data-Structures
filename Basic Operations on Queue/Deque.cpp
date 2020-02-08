#include<bits/stdc++.h>
using namespace std;
#define N 5

class Deque{
    public:
    int deq[N];
    int front = -1;
    int rear = -1;
    
    void enqueueFront(int value){
        if(front==(rear+1)%N ){
            cout<<"Overflow condition.\n";
        }
        else if(front==-1){
            front++; rear++;
            deq[front] = value;
        }
        else if(front==0){
            front = N-1;
            deq[front] = value;
        }
        else{
            front--;
            deq[front] = value;
        }
    }
    
    void enqueueRear(int value){
        if(front==(rear+1)%N ){
            cout<<"Overflow condition.\n";
        }
        else if(front==-1){
            front++; rear++;
            deq[front] = value;
        }
        else if(rear == N-1){
            rear = 0;
            deq[rear] = value;
        }
        else{
            rear++;
            deq[rear] = value;
        }
    }
    
    void displayDeque(){
        int temp = front;
        while(temp != rear){
            cout<<deq[temp]<<"\t";
            temp = (temp+1)%N;
        }
        cout<<deq[temp];
        cout<<"\n";
    }
    
    void dequeueFront(){
        if(front == -1){
            cout<<"Underflow Condition.\n";
        }
        else if(front == rear){
            cout<<"Deleting: "<<deq[front]<<"\n";
            front = -1;
            rear = -1;
        }
        else if(front == N-1){
            cout<<"Deleting: "<<deq[front]<<"\n";
            front = 0;
        }
        else{
            cout<<"Deleting: "<<deq[front]<<"\n";
            front++;
        }
    }
    
    void dequeueRear(){
        if(rear == -1){
            cout<<"Underflow Condition.\n";
        }
        else if(front == rear){
            cout<<"Deleting: "<<deq[rear];
            front = -1;
            rear = -1;
        }
        else if(rear == 0){
            cout<<"Deleting: "<<deq[rear];
            rear = N-1;
        }
        else{
            cout<<"Deleting: "<<deq[rear]<<"\n";
            rear--;
        }
    }
};

int main(){
    Deque ele;
    ele.enqueueFront(5);
    ele.enqueueFront(6);
    ele.enqueueRear(7);
    ele.enqueueRear(8);
    ele.enqueueFront(4);
    ele.displayDeque();
    ele.dequeueRear();
    ele.dequeueFront();
    ele.dequeueFront();
    ele.dequeueFront();
    ele.dequeueFront();
    ele.dequeueRear();
    ele.displayDeque();
    
    return 0;
}








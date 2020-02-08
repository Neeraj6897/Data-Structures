#include<bits/stdc++.h>
using namespace std;
#define N 5

class static_circularQueue{
    public:
    int a[N];
    int front = -1;
    int rear = -1;
    
    void enqueue(int value){
        if((rear+1)%N == front){
            cout<<"Queue is full.\n";
        }
        
        else if(front == -1){
            rear = (rear+1)%N;
            a[rear] = value;
            front = rear;
            //cout<<front<<"\n";
        }
        else{
            rear = (rear+1)%5;
            a[rear] = value;
        }
    }
    
    void dequeue(){
        if(front == -1){
            cout<<"Underflow condition.\n";
        }
        else if(rear==front){
            front = rear = -1;
        }
        else{
            cout<<"Deleting element: "<<a[front]<<"\n";
            front = (front+1)%N;
        }
    }
    
    void displayQueue(){
        if(front == -1){
            cout<<"Empty queue.\n";
        }
        
        else{
            int temp = front;
            while(temp != rear){
                cout<<a[temp]<<"\t";
                temp = (temp+1)%N;
            }
            cout<<a[temp];
            cout<<"\n";
        }
    }
};

int main(){
    static_circularQueue ele;
    ele.enqueue(5); ele.enqueue(6); ele.enqueue(7); ele.enqueue(8); 
    ele.enqueue(9);
    ele.displayQueue();
    ele.dequeue();
    ele.dequeue();
    ele.dequeue();
    ele.displayQueue();
    ele.enqueue(10);
    ele.displayQueue();
    
    return 0;
}




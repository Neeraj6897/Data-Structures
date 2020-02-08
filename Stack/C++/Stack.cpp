#include <bits/stdc++.h>
using namespace std;

class static_stack{
    public:
    int a[5];
    int top = -1;
    
    void push(int value){
        //CHECK FOR OVERFLOW CONDITION OF STACK
        a[++top] = value;
    }
    
    void display_stack(){
        if(top == -1){
            cout<<"Static Stack is empty."<<"\n";
        }
        else{
            for(int i = top; i>=0; i--){
                cout<<a[i]<<"\t";
            }
            cout<<"\n";
        }
    }
    
    void pop(){
        //CHECK FOR UNDERFLOW CONDITION OF STACK
        cout<<"Popping out: "<<a[top]<<"\n";
        top--;
    }
    
};

class Node{
    public:
    int data;
    Node *next;
};

class dynamic_stack{
    private:
    Node * top;
    public:
    dynamic_stack(){
        top = NULL;
    }
    
    void push(int value){
        Node *temp = new Node;
        if(top == NULL){
        temp->data = value;
        temp->next = NULL;
        top = temp;
        }
        
        else{
            temp->data = value;
            temp->next = top;
            top = temp;
        }
    }
    
    void display_stack(){
        Node *temp = new Node;
        temp = top;
        while(temp != NULL){
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
    void pop(){
        Node *temp;
        temp = top;
        cout<<"Popping out: "<<temp->data<<"\n";
        top = temp->next;
        free(temp);
    }
};



int main(){
    static_stack ele;
    ele.push(5); ele.push(3); ele.push(8); ele.push(9);
    ele.display_stack();
    ele.pop();
    ele.display_stack();
    dynamic_stack element;
    element.push(5); element.push(3); element.push(8); element.push(9);
    element.display_stack();
    element.pop();
    element.display_stack();

    return 0;
}




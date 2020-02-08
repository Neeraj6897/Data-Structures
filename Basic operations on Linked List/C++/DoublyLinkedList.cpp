#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * pre;
    Node * next;
};

class Doubly_linked_list{
    private:
    Node * head;
    Node * tail;
    
    public:
    Doubly_linked_list(){
        head = NULL;
        tail = NULL;
    }
    
    void createNode(int value){
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        temp->pre = NULL;
        
        if(head==NULL){
            head = temp;
            tail = temp;
        }
        else{
            insert_end(value);
        }
    }
    
    void displayList(){
        Node *temp;
        temp = head;
        while(temp != NULL){
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
    void insert_front(int value){
        Node *temp = new Node;
        temp->data = value;
        temp->next = head;
        temp->pre = NULL;
        head = temp;
    }
    
    void insert_end(int value){
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        temp->pre = tail;
        tail->next = temp;
        tail = temp;
    }
    
    void insert_at_pos(int index, int value){
        Node *temp = new Node;
        Node *cur = new Node;
        if(index==1){
            insert_front(value);
        }
        else{
        cur = head;
        for(int i=1; i<index-1;i++){
            cur = cur->next;
        }
        temp->data = value;
        temp->pre = cur;
        temp->next = cur->next;
        cur->next->pre = temp;
        cur->next = temp;
        }
    }
    
    void delete_first(){
        Node *temp;
        temp = head;
        head = head->next;
        delete temp;
    }
    
    void delete_last(){
        Node *temp;
        temp = tail;
        tail = tail->pre;
        tail->next = NULL;
        free(temp);
    }
    
    void delete_at_pos(int index){
        Node *cur = new Node;
        Node *temp = new Node;
        cur = head;
        for(int i=1; i<index-1; i++){
            cur = cur->next;
        }
       /* 
       cur->next->pre = cur->pre;
       cur->pre->next = cur->next;
       free(cur);
       */
       temp = cur->next->next;
       cur->next = temp;
       temp->pre = cur;
       
    }
    
    void reverse_list(){
        Node *temp = new Node;
        Node *cur = new Node;
        cur = head;
       while(cur != NULL){
           temp = cur->next;
           cur->next = cur->pre;
           cur->pre = temp;
           cur = temp;
       }
       temp = head;
       head = tail;
       tail = temp;
    }
        
    
};

int main(){
    Doubly_linked_list element;
    element.createNode(10);
    element.createNode(11);
    element.insert_front(9);
    element.insert_end(12);
    element.insert_at_pos(4,18);
    element.displayList();
    element.delete_at_pos(2);
    element.reverse_list();
    element.displayList();
    
    return 0;
}





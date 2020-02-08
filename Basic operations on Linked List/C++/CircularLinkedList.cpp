#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
};

class Circular_Linked_List{
    private:
    Node * head;
    
    public:
    Circular_Linked_List(){
        head = NULL;
    }
    
    void create_Node(int value){
        
        Node * cur = new Node;
        Node *temp = head;
        cur->data = value;
        cur->next = head;
        
        if(head!=NULL){
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = cur;
        }
        
        else{
            cur->next = cur;
        }
        head = cur;
        
       /* 
        if(head == NULL){
            Node *temp = new Node;
            temp->data = value;
            temp->next = temp;
            head = temp;
        }
        
        else{
            Node *temp = new Node;
            Node *cur = new Node;
            while(temp->next != head){
                temp = temp->next;
            }
            cur->data = value;
            cur->next = head;
            temp->next = cur;
            head = cur;
        }
       */
       
    }
    
    void insert_last(int value){
           Node *temp;
           Node *cur = new Node;
           temp = head;
           while(temp->next != head){
               temp = temp->next;
           }
           cur->data = value;
           cur->next = head;
           temp->next = cur;
       }
    
    void displayList(){
        Node *temp;
        temp = head;
        if(head == NULL){
            cout<<"Empty"<<"\n";
        }
        else if(head != NULL){
        do{
            cout<<temp->data<<"\t";
            temp = temp->next;
        } while(temp != head);
        cout<<"\n";
    }
    }
    
    void insert_at_pos(int index, int value){
        Node *temp;
        Node *cur = new Node;
        temp = head;
        int count = 1;
        while(temp->next != head){
            count++;
            temp = temp->next;
        }
        if(index == 1){
            create_Node(value);
        }
        else if(count+1 == index){
            insert_last(value);
        }
        else{
            temp = head;
        for(int i=1; i<index-1; i++){
            temp = temp->next;
        }
        cur->data = value;
        cur->next = temp->next;
        temp->next = cur;
    }
    }
    
    void delete_at_pos(int pos){
        int count = 1;
        Node *temp;
        temp = head;
        while(temp->next != head){
            temp = temp->next;
            count++;
        }
        
        if(pos == 1){
        Node *temp, *cur;
        temp = head;
        cur = temp->next;
        while(temp->next != head){
            temp = temp->next;
        }
        head = cur;
        temp->next = head;
        }
        
        else if(pos == count){
            Node *temp;
            temp = head;
            for(int i=1; i<pos-1; i++){
                temp = temp->next;
            }
            temp->next = head;
        }
        
        else{
             Node *temp;
            temp = head;
            for(int i=1; i<pos-1; i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
    }
    
    void reverse_list(){
        Node *pre, *cur, *last;
        last = head;
        pre = head;
        cur = head->next;
        head = head->next;
        while(last != head){
            head = head->next;
            cur->next = pre;
            pre = cur;
            cur = head;
        }
        cur->next = pre;
        head = pre;
    }
};

int main(){
    Circular_Linked_List ele;
    ele.create_Node(9);
    ele.create_Node(10);
    ele.insert_last(11);
    ele.insert_at_pos(1, 18);
    ele.displayList();
    //ele.delete_at_pos(3);
    ele.reverse_list();
    ele.displayList();
    return 0;
}






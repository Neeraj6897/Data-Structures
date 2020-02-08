#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node * next;
};

class linked_list{
    private:
    node * head;
    node * tail;
    
    public:
    linked_list(){
        head = NULL;
        tail = NULL;
    }
    
    void createNode(int val);
    void displayList();
    void insert_start(int val);
    void insert_end(int val);
    void insert_at_pos(int p, int val);
    void delete_first();
    void delete_last();
    void reverse_list();
};

void linked_list::createNode(int value){
    node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    
    if(head==NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    }
    
    else {
        tail->next = temp;
        tail = temp;
    }
}

void linked_list::displayList(){
    node *temp ;//= new node;
    temp = head;
    while(temp != NULL){
        cout << temp->data<<"\t";
        temp = temp->next;
    }
    cout<<"\n";
}

void linked_list::insert_start(int value){
    node *temp = new node;
    temp->data = value;
    temp->next = head;
    head = temp;
}

void linked_list::insert_end(int value){
    node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}

void linked_list::insert_at_pos(int pos, int value){
    node *temp = new node;
    node *cur = new node;
    node *pre = new node;
    cur = head;
    int count = 0;
    while(cur->next != NULL){
        cur = cur->next;
        count++;
    }
    if((count+1)>pos){
        cur = head;
        for(int i=1; i<pos; i++){
            pre = cur;
            cur = cur->next;
        }
        temp->data = value;
        temp->next = cur;
        pre->next = temp;
    }
    else{
        cout<<"Position should be less than or equal to "<<(count+1)<<"\n";
    }

}

void linked_list::delete_first(){
    node *temp;
    temp = head;
    head = head->next;
    delete temp;
}

void linked_list::delete_last(){
    node *cur;
    node *pre;
    cur = head;
    while(cur->next != NULL){
        pre = cur;
        cur = cur->next;
    }
    tail = pre;
    tail->next = NULL;
    delete cur;
}

void linked_list::reverse_list(){
    node *pre = new node;
    node *cur = new node;
    node *nxt = new node;
    cur = head;
    pre = NULL;
    nxt = NULL;
    
    while(cur != NULL){
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    head = pre;
}

int main(){
    int val;
    val = 10;
    linked_list ele;
    ele.createNode(val);
    ele.insert_end(11);
    ele.insert_start(9);
    ele.insert_at_pos(2,18);
    ele.displayList();
    ele.reverse_list();
    ele.displayList();
    return 0;
}












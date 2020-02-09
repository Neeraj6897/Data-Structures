#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

//Inorder traversal Using Recursion
void inorder(Node *root){
    if(root == NULL ){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//Preorder traversal Using Recursion
void preorder(Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//Postorder Traversal Using Recursion
void postorder(Node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//Inorder Traversal using Iterative method

void inorder_iterative(Node *root){
    stack<Node *>stack;
    Node *cur = root;
    while(cur != NULL || !stack.empty()){
        if(cur != NULL){
            stack.push(cur);
            cur = cur->left;
        }
        else{
            cur = stack.top();
            cout<<cur->data<<" ";
            stack.pop();
            cur = cur->right;
        }
    }
}

//Preorder Traversal using Iterative method

void preorder_iterative(Node *root){
    stack<Node *>stack;
    Node *cur = root;
    stack.push(cur);
    while(!stack.empty()){
        if(cur != NULL){
            cout<<cur->data<<" ";
            
            if(cur->right){
                stack.push(cur->right);
            }
            cur = cur->left;
        }
        else{
            cur = stack.top();
            stack.pop();
        }
    }
}

//Postorder Traversal Using Iterative method
void postorder_iterative(Node *root){
    stack<Node*> stack1;
    stack< int >out;
    stack1.push(root);
    while(!stack1.empty()){
        Node * cur;
        cur = stack1.top();
        stack1.pop();
        out.push(cur->data);
        if(cur->left){
            stack1.push(cur->left);
       }
        if(cur->right){
            stack1.push(cur->right);
        }
    }
   
    while(!out.empty()){
        cout<<out.top()<<" ";
        out.pop();
    }
    
}

int main(){
    Node * root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(9);
    root->left->left = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(8);
    postorder(root);
    cout<<"\n";
    postorder_iterative(root);
}



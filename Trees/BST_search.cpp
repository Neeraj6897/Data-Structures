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

void inorder(Node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void search_bst(int key, Node * &root){
    if(root->data == key){
        cout<<key<<" Found\n";
    }
    else if(root->data > key){
        if(root->left != NULL){
            root = root->left;
            search_bst(key, root);
        }
        else{cout<<key<<" Not found\n";}
    }
    else if(root->data < key){
        if(root->right != NULL){
            root = root->right;
            search_bst(key, root);
        }
        else{cout<<key<<" Not found\n";}
    }
}

int main(){
    Node * root = NULL;
    root = new Node(12);
    root->left = new Node(6);
    root->right = new Node(14);
    root->left->left = new Node(5);
    root->left->right = new Node(7);
    root->right->left = new Node(13);
    root->right->right = new Node(15);
    inorder(root);
    cout<<"\n";
    search_bst(13, root);
    return 0;
}

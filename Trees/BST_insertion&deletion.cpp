#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right;
    
    Node(){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }    
};

void inorder(Node * value){
    if(value == NULL){
        return;
    }
    inorder(value->left);
    cout<<value->data<<" ";
    inorder(value->right);
}

void insertNode(int key, Node* &root)   //&root becoz to access value of (Node*) address operator has to be used 
    {
        if(root == NULL){
            Node* temp = new Node();
            temp->data = key;
            temp->left = NULL;
            temp->right = NULL;
            root = temp;
        }
        else if(root->data > key){
            //root = root->left;
            insertNode(key, root->left);
        }
        else if(root->data < key){
            //root = root->right;
            insertNode(key, root->right);
        }
        
        else{
            cout<<"Duplicate\n";
        }
    }
    
int findmax(Node * root){
    Node * cur = root;
    while(cur->right){
        cur = cur->right;
    }
    return cur->data;
}    
    
void deleteNode(int value, Node * &root)
{
    if(root == NULL){
        return;
    }    
    
    else if(root->data > value){
        deleteNode(value, root->left);
    }
    else if(root->data < value){
        deleteNode(value, root->right);
    }
    //Now if root->data == key then
    else{
        //if no child
        if(root->left==NULL && root->right==NULL){
            delete root;
            root = NULL;
        }
        //if two child
        else if(root->left && root->right){
            int max = findmax(root);
            root->data = max;
            deleteNode(max, root->right);
        }
        else{
            if(root->left){
                Node *cur = root;
                root = root->left;
                delete cur;
                
            }
            else if(root->right){
                Node *cur = root;
                root = root->right;
                delete cur;
            }
        }
    }
}

int main(){
    Node * root = NULL;
    insertNode(12, root);
    insertNode(6, root);
    insertNode(14, root);
    insertNode(5, root);
    insertNode(7, root);
    insertNode(13, root);
    insertNode(15, root);
    insertNode(16, root);
    inorder(root);
    deleteNode(12, root);
    cout<<"\n";
    inorder(root);
    
    return 0;
}







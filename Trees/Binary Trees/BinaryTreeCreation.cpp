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
    //Node *createNode();
    
};

void insert(int value, Node *leaf){
    if(leaf->left != NULL){
        insert(value, leaf->left);
        if(leaf->right != NULL){
            insert(value, leaf->right);
        }
        else{
            //leaf->right = new Node;
            leaf->right->data = value;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
    else{
        //leaf->left = new Node;
        leaf->left->data = value;
        leaf->left->left = NULL;
        leaf->left->right = NULL;
    }
}

void inorder(Node * value){
    if(!value){
        return;
    }
    inorder(value->left);
    cout<<value->data<<" ";
    inorder(value->right);
}

//--------------------------Values can be assigned during runtime(Recursion is used)--------------------------------------------------

/*Node * Node::createNode(){
        Node *temp = new Node();
        int value;
        cout<<"Enter value: ";
        cin>>value;
        if(value==-1){
            return NULL;
        }
        else{
            temp->data = value;
            temp->left = createNode();
            temp->right = createNode();
            return temp;
        }
    }
*/
int main(){
    /*
    Node ele;
    Node *root=0;
    root = ele.createNode();
    cout<<root->data<<"\n";
    cout<<root->left->data<<"  "<<root->right->data<<"\n";
    */
    
    //-------------Argument in Node() constructor should be changed to Node(int value) to use this----------------
    
    Node * root = NULL;
    root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(9);
    root->left->left = new Node(7);
    //root->left->right = NULL;//new Node(12);
    root->right->left = new Node(15);
    root->right->right = new Node(8);
    cout<<root->data<<"\n";
    cout<<root->left->data<<"  "<<root->right->data<<"\n";
    cout<<root->left->left->data<<"  "<</*root->left->right->data<<*/"  "<<root->right->left->data<<"  "<<root->right->right->data<<"\n";
    insert(12, root);
    inorder(root);
    return 0;
}





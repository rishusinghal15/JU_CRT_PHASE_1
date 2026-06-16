#include<iostream>
#include<limits.h>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std; 

class Node{
    public: 
    int data; 
    Node* left; 
    Node* right; 

    Node(int val){
        data = val; 
        left = NULL; 
        right = NULL; 
    }
};

// return root node of the tree
Node* buildTree(){
    int val; 
    cin >> val; 

    if(val==-1){
        return NULL;
    } else {
        Node* root = new Node(val); 
        // 1 case mne krdiya, baaaki recursion 
        root->left = buildTree(); 
        root->right = buildTree(); 
        return root; 
    }
}

// NLR 
// Preorder Traversal 
void preOrderTraversal(Node* root){
    //base case
    if(root==NULL){
        return; 
    }
    // 1 case m solve krunga baaki recursion kr lega 
    cout << root->data << " "; 
    // L
    preOrderTraversal(root->left); 
    // R
    preOrderTraversal(root->right); 
}

//LNR
void inOrderTraversal(Node* root){
    // base case 
    if(root == NULL){
        return; 
    } 
    // L
    inOrderTraversal(root->left); 
    // N
    cout << root->data << " "; 
    // R
    inOrderTraversal(root->right); 
}

// LRN 
void postOrderTraversal(Node* root){
    // base case 
    if(root == NULL){
        return; 
    }
    // L
    postOrderTraversal(root->left); 
    // R
    postOrderTraversal(root->right); 
    // N 
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root){
    // empty tree
    if(root==NULL){
        return; 
    } 
    // LOT 
    queue<Node*> q;
    // initial state maintain 
    q.push(root);
    // Using NULL as a marker 
    q.push(NULL); 

    while(!q.empty()){
        Node* front = q.front();
        q.pop(); 
        if(front == NULL){
            // current level ki saari node print ho chuki h 
            // go to next line 
            cout << endl; 
            // agar q empty h then do not insert NULL -> infinite loop fass sktaa h
            // agar q non empty h, then insert NULL -> to indicate the rightmost 
            // node or end of line 
            if(!q.empty()){
                q.push(NULL); 
            }
        } else {   
        cout << front->data << " ";
        if(front->left !=NULL){
            q.push(front->left); 
        }
        if(front->right!= NULL){
            q.push(front->right); 
        }
        }
    }
}

int main() {
    // 10 20 30 -1 -1 40 -1 -1 50 -1 60 -1 -1 
    Node* root = buildTree(); 
    cout << endl; 
    cout << "Printing Preorder Traversal: " << endl; 
    preOrderTraversal(root);
    
    cout << endl; 
    cout << "Printing Inorder Traversal: " << endl; 
    inOrderTraversal(root);

    cout << endl; 
    cout << "Printing Postorder Traversal: " << endl; 
    postOrderTraversal(root);

    cout << endl; 
    cout << "Printing Levelorder Traversal: "; 
    levelOrderTraversal(root);


    return 0; 
}
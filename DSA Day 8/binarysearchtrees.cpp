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

Node* buildBST(Node* root, int val){
    if(root==NULL){
        root = new Node(val); 
        return root; 
    } else {
        if(val > root->data){
            root->right = buildBST(root->right, val); 
        } else {
            root->left = buildBST(root->left, val); 
        }
        return root; 
    }
}

Node* createBST(Node* root){
    cout << "Enter the value of the node: "<< endl;
    int val; 
    cin >> val; 
    // jab val -1 hogii tbb rukna h, agar val -1 nii h toh mat ruko
    while(val!=-1){
        root = buildBST(root, val); 
        cin >> val; 
    }
    return root; 
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
    queue<Node*> q; 
    // initial state maintain 
    q.push(root); 
    q.push(NULL); 

    while(!q.empty()){
        Node* front = q.front(); 
        q.pop(); 
        if(front==NULL){
            // iska mtlb current level ki saari node travel ho chuki h 
            cout << endl; 
            if(!q.empty()){
                q.push(NULL); 
            }
        } else {
            cout << front->data << " "; 
            if(front->left){
                q.push(front->left); 
            }
            if(front->right){
                q.push(front->right); 
            }
        }
    }
}

int main(){
    // 100 50 150 40 60 120 180 -1
    Node* root = NULL; 
    root = createBST(root); 

    cout << endl; 
    cout << "Printing Preorder: "; 
    preOrderTraversal(root); 

    cout << endl << "Printing Inorder: "; 
    inOrderTraversal(root); 

    cout << endl << "Printing PostOrder: "; 
    postOrderTraversal(root); 

    cout << endl << "Printing Levelorder: "; 
    levelOrderTraversal(root); 

    return 0; 
}

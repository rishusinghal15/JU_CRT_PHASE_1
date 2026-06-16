#include<iostream> 
using namespace std; 

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

// Insertion at Head 
void InsertAtHead(int val, Node* &head, Node* &tail){
    
    if(head == NULL && tail == NULL ){
        // Empty Linked List 
        // Step1: Create a new node
        Node* newNode = new Node(val); 
        // Step 2: point head and tail on that node 
        head = newNode; 
        tail = newNode; 
    }
    else{ 
        // Non - Empty Linked List 
        // Step1: Create a new node 
         Node* newNode = new Node(val); 
        // Step2: Link the new node to the original Linked List 
        newNode ->next = head; 
        // Step3: Update head to the new node 
        head = newNode; 
    }
    // return the head of the modified linked list 
    // return head; 
}

// Insertion at tail 
void InsertAtTail(int val, Node* &head, Node* &tail){
    if(head==NULL && tail == NULL){
        Node * newNode = new Node(val); 
        head = newNode; 
        tail = newNode; 
    }
    else {
        Node* newNode = new Node(val); 
        tail->next = newNode; 
        tail = newNode; 
    }
    // return head; 
}

// Traversal over the Linked List 
void printLinkedList(Node* &head){
    Node* temp = head; 

    while(temp!= NULL){
        cout << temp->data << "->"; 
        temp = temp->next; 
    }
    cout << endl; 
}

bool serachInLinkedList(int target, Node* &head){
    Node* temp = head; 

    while(temp!=NULL){
        if(temp->data == target){
            return true; 
        }
        else{ 
            // go to next node 
            temp = temp->next; 
        }
    }
    // Puri list traverse krne k baad bhi koi target value nii mili 
    return false; 
}

// find length of linkedList 
int getLengthOfLinkedList(Node* head){
    int len =0; 
    Node* temp = head; 

    while(temp!=NULL){
        // count node
        len++; 
        // move to next node 
        temp = temp->next; 
    }
    return len; 
}

void InsertAtPosition(int pos, int val, Node* &head, Node* &tail){
    // assuming the position will be always inside not out of bound 

    // checking out of bound val of position 
    // valid range -> 1 to length+1;
        int length = getLengthOfLinkedList(head);  
    if(pos<1 || pos>length+1 ){
        return ; 
    }
    if(pos==1){
        InsertAtHead(val, head,tail); 
        return; 
    }
    if(pos== length+1){
        InsertAtTail(val, head, tail); 
        return; 
    }
    else{ 
        // middle ki pos h koi 
        // Step1: Create new node
        Node* newNode = new Node(val);
        Node* temp = head;  
        // Step2: temp var ko pos-1 reach kraoo
        for(int i=0; i<pos-1; i++){
            temp = temp->next; 
        } 
        // Step3: newNode ko temp->next se connect kia tha 
        newNode->next = temp->next; 
        // Step4: temp ko new node se connect kiyaa thaa
        temp->next = newNode; 
    }
}

void deleteFromPosition(int pos, Node* &head, Node* &tail){
    // invalid cases
    int length = getLengthOfLinkedList(head); 

    if(pos>length){
        return; 
    } 

    if(head==NULL && tail == NULL){
        return; 
    }

    // position = 1 and LL single node 
    if(head==tail && pos==1){
        Node* temp = head; 
        head = NULL; 
        tail = NULL; 
        delete temp; 
        return; 
    }

    // LL has multiple nodes but pos = 1
    if(pos==1){
        Node* temp = head; 
        head = head->next; 
        temp->next = NULL; 
        delete temp; 
        return; 
    } else{
        // Either you are deleting last nodes or middle nodes 
        // Step1: Setup cuurent/previous/forward 
        Node* previous = head; 
        for(int i =1; i<pos-2;i++){
            previous = previous->next; 
        }
        Node* current = previous->next; 
        Node* forward = current->next; 

        // Update links
        current->next = NULL;
        previous->next = forward; 
        // current is isolated now
        delete current; 
    }
}

int main(){

    // Empty Linked List 
    Node* head = NULL ;
    Node* tail = NULL ; 

    InsertAtHead(10, head, tail); 
    InsertAtHead(20, head, tail);
    InsertAtHead(30, head, tail);
    InsertAtTail(40,head, tail); 
    // printLinkedList(head); 

    InsertAtPosition(3,500,head,tail); 
    cout << endl << "Modified List: "<< endl; 
    printLinkedList(head); 

    // deleteFromPosition(1,head,tail); 
    // cout << endl << "Modified List: "<< endl; 
    // printLinkedList(head); 

    // cout<< getLengthOfLinkedList(head) << endl; 
    // cout << serachInLinkedList(80,head); 
}
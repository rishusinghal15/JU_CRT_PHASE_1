#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(int val, Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
    {
        // Case1: LL is empty
        Node *newNode = new Node(val);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Case2: LL is not empty
        Node *newNode = new Node(val);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Traversal over the Linked List
void printLinkedList(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void printReverse(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

void insertAtTail(int val, Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
    {
        // Case1: LL is empty
        Node *newNode = new Node(val);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Case2: LL is not empty
        Node *newNode = new Node(val);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int getLength(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtPosition(int pos, int val, Node *&head, Node *&tail)
{
    // 3 cases -> leftmost, rightmost and middle of the LL
    int len = getLength(head);
    if (pos == 1)
    {
        insertAtHead(val, head, tail);
    }
    else if (pos == len + 1)
    {
        // rightmost end
        insertAtTail(val, head, tail);
    }
    else
    {
        // middle m kisi position prr
        Node *temp = head;
        // temp ko pos-2 step aage bdhaoo
        for (int i = 0; i < pos - 2; i++)
        {
            temp = temp->next;
        }
        // create node
        Node *newNode = new Node(val);
        // forward pointer set
        Node *forward = temp->next;
        // pointers set krdo
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = forward;
        forward->prev = newNode;
    }
}

bool searchElement(Node *&head, int target)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtPosition(int pos, Node *&head, Node *&tail)
{
    // LL is empty
    int len = getLength(head);
    if (head == NULL && tail == NULL)
    {
        cout << " no nodes to delete";
        return;
    }
    else if (head == tail)
    {
        // single node
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else if (pos == 1)
    {
        // we want to delete head node
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else if(len == pos){
        Node* temp = tail; 
        tail = temp->prev; 
        tail->next = NULL; 
        temp->prev = NULL; 
        delete temp; 
    }
    else
    {
        // we want to delete any node other than head
        Node *backward = head;
        for (int i = 0; i < pos - 2; i++)
        {
            backward = backward->next;
        }
        Node* curr = backward->next;
        Node* forward = curr->next;
        backward->next = forward;
        forward->prev = backward;
        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
    }
}

void reverseLinkedList(Node* &head){
    // Empty LL 
    if(head == NULL){
        return ; 
    }
    // setting up prev and curr 
    Node* prev = NULL; 
    Node* curr = head; 

    // update links
    while(curr!=NULL){
        Node* forward = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = forward; 
    }
    // update head 
    head= prev; 
}

Node* reverseLLRecursive(Node* &head, Node* & prev){
    // return the head of reverse LL
    if(head==NULL){
        return prev; 
    }
    // 1 case hum solve krenge
    Node* curr = head; 
    Node* forward = curr->next; 
    curr->next = prev; 

    // Abb tkk 1 case solve hogya h 
    // Now recursive call 
    return reverseLLRecursive(forward, curr); 
}

// returns the middle node of a LL
Node* getMiddle(Node* head){
    Node* slow = head; 
    Node* fast = head; 

    while(fast!= NULL && fast->next!= NULL){
        slow = slow->next; 
        fast = fast->next->next; 
    }
    return slow; 
}

bool checkPaindromeLL(Node* head){
    // find length of LL
    int len = getLength(head);  
    // find mid
    Node* mid = getMiddle(head); 
    // Update mid as per Even/Odd
    // Even length m mid ko as it is use krna h 
    //Odd Length m main final Mid , mid->next kr lunga 
    Node* finalMid = NULL; 
    if(len&1){
        // odd
        finalMid =  mid->next; 
    } else{
        // even 
        finalMid = mid; 
    }
    // Reverse LL starting from mid node
    reverseLinkedList(finalMid); 
    // Now I have 2 linked List with starting pointer as head and final Mid 
    // compare and return true/false 
    Node* temp = head;
    while(temp!= NULL && finalMid!= NULL){
        if(temp->data != finalMid->data){
            return false; 
        }
        temp = temp->next; 
        finalMid = finalMid->next; 
    }
    return true; 

}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtTail(11, head, tail);
    // 10->NULL
    insertAtTail(11, head, tail);
    // 10->20->NULL
    insertAtTail(11, head, tail);
    insertAtTail(11, head, tail);
    // 10->20->30->NULL
    // printLinkedList(head);

    cout << checkPaindromeLL(head); 

    // insertAtPosition(2, 420, head, tail);
    // printLinkedList(head);

    // Node* mid= getMiddle(head); 
    // cout << mid->data << endl; 
    // deleteAtPosition(4, head, tail); 
    // printLinkedList(head); 

    // reverseLinkedList(head); 
    // printLinkedList(head); 

    // Node* prev = NULL; 
    // head = reverseLLRecursive(head, prev);
    // printLinkedList(head);  

    // insertAtHead(10, head, tail);
    // // 10->NULL
    // insertAtHead(20, head, tail);
    // // 20->10->NULL
    // insertAtHead(30, head, tail);
    // // 30->20->10->NULL
    // printLinkedList(head);
    // printReverse(tail);
    return 0;
}
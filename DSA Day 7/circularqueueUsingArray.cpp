#include <iostream>
#include <queue>
using namespace std;

class Cqueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Cqueue(int capacity)
    {
        arr = new int[capacity];
        size = capacity;
        front = -1;
        rear = -1;
    }

    void push(int val){
        // 4 case: overflow, empty, circular queue, normal case
        if((front == 0 && rear == size-1) || (rear == front -1)){
            cout << "Overflow" << endl; 
        } else if(front == -1 && rear == -1){
            front++; 
            rear++; 
            arr[rear] = val ;
        } else if(rear == size-1 && front !=0){
            rear = 0; 
            arr[rear]=val; 
        } else {
            // normal case
            rear ++; 
            arr[rear]= val; 
        }
    }

    void pop(){
        // 4 case: Underflow, empty, Circular nature, normal case
        if(front == -1 && rear == -1){
            cout << "Underflow" << endl; 
        } else if(front == rear){
            arr[front]= -1; 
            front = -1; 
            rear = -1; 
        } else if(front == size-1){
            arr[front] = -1; 
            front = 0; 
        } else {
            // normal case 
            arr[front] = -1; 
            front++; 
        }
    }

    int getSize(){
        // Dimmag lgana pdega 
        // Empty case 
        // case1: rear >= front 
        // case2: rear < front 
        if(front == -1 && rear == -1){
            return 0; 
        } else if(rear >= front){
            return rear-front+1; 
        } else {
            // rear < front 
            return size-front+rear+1; 
        }
    }

    int getFront(){
        if(front==-1){
            cout << "There is no element" << endl; 
        } else {
            int val = arr[front]; 
            return val; 
        }
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true; 
        } else {
            return false; 
        }
    }

    void print(){
        for(int i=0;i<size; i++){
            cout << arr[i] << " "; 
        } cout << endl; 
    }
};

int main() {
    Cqueue cq(5); 

    cq.push(1); 
    cq.push(2); 
    cq.push(3); 
    cq.push(4); 
    cq.push(5); 

    cq.print();

    cq.pop();
    cq.pop(); 
    cq.print(); 

    cq.push(6); 
    cq.print();

    cq.pop(); 
    cq.print();
    
    cq.pop(); 
    cq.print();

    cq.pop(); 
    cq.print();

    cq.pop(); 
    cq.print();

}
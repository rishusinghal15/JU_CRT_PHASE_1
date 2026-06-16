#include <iostream>
#include <queue>
using namespace std;

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int capacity)
    {
        arr = new int[capacity];
        size = capacity;
        front = -1;
        rear = -1;
    }

    void pushFront(int val)
    {
        // 3 cases: Overflow, Empty Queue m insert - single element, normal
        if (front == 0)
        {
            cout << "Overflow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[front] = val;
        }
        else
        {
            front--;
            arr[front] = val;
        }
    }

    void pushBack(int val)
    {
        // 3 cases: Overflow, Empty Queue m insert - single element, normal
        if (rear == size - 1)
        {
            cout << "Overflow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void popFront()
    {
        // 3 cases: underflow, empty queue - single element, normal
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
        }
        else if (front == rear)
        {
            arr[front] = -1; 
            front = -1;
            rear = -1;
        }
        else
        {
            arr[front]= -1; 
            front++;
        }
    }

    void popBack()
    {
        // 3 cases: underflow, empty queue - single element, normal
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
        }
        else if (front == rear)
        {
            arr[rear]=-1; 
            front = -1;
            rear = -1;
        }
        else
        {
            arr[rear]=-1; 
            rear--;
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    Deque dq(7); 

    
    dq.pushFront(10); 
    dq.pushBack(12);
    dq.pushBack(14); 
    dq.pushBack(16);  
    dq.print();

    dq.popFront(); 
    dq.popBack(); 
    dq.print(); 


    return 0; 
}
#include <iostream>
#include <queue>
using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int capacity)
    {
        arr = new int[capacity];
        size = capacity;
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        // Overflow
        if (rear == size - 1)
        {
            cout << "Overflow";
            return;
        }
        // First Element
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        // Normal Insertion
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void pop()
    {
        // Underflow
        if (front == -1 && rear == -1)
        {
            cout << "Underflow";
            return;
        }
        // Single Element
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else
        {
            // Normal Pop
            arr[front] = -1;
            front++;
        }
    }

    int getSize()
    {
        if (front == -1 && rear == -1)
        {
            return 0;
        }
        else
        {
            return rear - front + 1;
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

    int getFront()
    {
        if (front == -1)
        {
            cout << "There is no element";
            return -1;
        }
        else
        {
            int val = arr[front];
            return val;
        }
    }

    int getRear()
    {
        if (rear == -1)
        {
            cout << "There is no element";
            return -1;
        }
        else
        {
            int val = arr[rear];
            return val;
        }
    }
};

int main()
{
    Queue q(5);

    q.push(5);
    q.push(15);
    q.push(25);

    cout << q.getFront() << endl; 
    cout << q.getRear() << endl; 
    // cout << q.getSize() << endl;

    // q.pop(); 
    // q.pop(); 
    // q.pop(); 

    // cout << q.getSize() << endl; 

    return 0;
}
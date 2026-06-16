#include <iostream>
using namespace std;

class Stack
{
    public: 
    int *arr;
    int size;
    int top;

    Stack(int capacity)
    {
        arr = new int[capacity];
        size = capacity;
        top = -1;
    }

    void push(int val)
    {
        if (top == size - 1)
        {
            // stack is already full, agar insert kroge toh stack overflow ho jaayegaa
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    void pop()
    {
        if(top==-1){
            cout <<"Stack Underflow" << endl; 
        } else{ 
            // normal case
            arr[top]=0; 
            top--;
        }
    }

    int getSize()
    {
        return top+1; 
    }

    bool isEmpty()
    {
        if(top==-1){
            return true; 
        } else{
            return false; 
        }
    }

    int getTop()
    {
        if(top==-1){
            cout << "There is no element at the top, as stack is empty";
            return -1; 
        } else{
            // normal case
            return arr[top];
        }
    }

    void print(){
        cout << "Printing Stack" << endl; 
        for(int i=0; i<size; i++){
            cout << arr[i] << " "; 
        } cout << endl; 
    }
};

int main()
{
    // Creating a stack of initial size 5 
    Stack s(5);  
    s.push(10); 
    s.push(20); 
    s.push(30); 
    s.push(40); 
    s.push(50);
    s.print();
    s.push(60);
    s.print();

    cout <<s.getTop() << endl;
    cout << s.getSize() <<endl;
    cout << s.isEmpty() << endl ;

    s.pop(); 
    s.print();
    s.pop(); 
    s.print();
    s.pop(); 
    s.print();
    s.pop(); 
    s.print(); 
    s.pop(); 
    s.print(); 
    s.pop(); 
    s.print(); 
    cout << s.getSize();


    return 0;
}
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q)
{
    // push all elements of q into stack
    stack<int> s;
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }
    // push all elements of stack into q
    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
}

void printQueue(queue<int> q)
{

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void reverseQueueUsingRecursion(queue<int>&q){
    // base case 
    if(q.empty()){
        return; 
    }
    // 1 case m solve krunga
    int element = q.front(); 
    q.pop(); 
    // Baaki recursion krega
    reverseQueueUsingRecursion(q); 
    // backtrack 
    q.push(element); 
}

int main()
{

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseQueueUsingRecursion(q); 
    // reverseQueue(q);

    printQueue(q);

    return 0;
}
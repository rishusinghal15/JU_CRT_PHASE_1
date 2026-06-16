#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &s, int val)
{

    // Base case
    if (s.empty())
    {
        s.push(val);
        return;
    }

    // 1 case, baaki recursion 
    if(val<=s.top()){
        s.push(val);
        return; 
    } else {
        // value > s.top()
        int topVal = s.top(); 
        s.pop(); 
        // recursion 
        insertSorted(s, val); 
        // Backtrack 
        s.push(topVal); 
    }
}

int main()
{

    stack<int> s;

    s.push(50);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10); 

    insertSorted(s, 32); 

    cout << "Printing Stack:" << endl; 
    while(!s.empty()){
        cout << s.top() << " "; 
        s.pop(); 
    }

    return 0;
}
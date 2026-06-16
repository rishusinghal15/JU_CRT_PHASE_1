#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // creation
    stack<int> s;
    // insertion
    s.push(10);
    s.push(20);
    s.push(30);

    // size
    cout << s.size() << endl;
    // Check stack is empty or not
    cout << s.empty() << endl;
    // peek
    cout << s.top() << endl;
    // remove
    s.pop();
    cout << s.top() << endl;

    return 0;
}
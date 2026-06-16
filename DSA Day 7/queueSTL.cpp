#include <iostream>
#include <queue>
using namespace std;

int main()
{

    // creation
    queue<int> q;
    // insertion
    q.push(5);
    q.push(51);
    q.push(52);
    q.push(53);
    // size
    cout << q.size() << endl;
    // empty
    if (q.empty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
    // front element
    cout << q.front() << endl;
    // rear element
    cout << q.back() << endl;
    // deletion
    q.pop();
    cout << q.size() << endl;

    return 0;
}
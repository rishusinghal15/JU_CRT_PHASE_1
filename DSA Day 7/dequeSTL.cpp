#include <iostream>
#include <queue>
using namespace std;

int main() {

    // creation
    deque<int> dq; 
    // insertion
    dq.push_front(5); 
    dq.push_back(10); 
    // size
    cout << dq.size() << endl; 
    // pop 
    dq.pop_back(); 
    dq.pop_front(); 
    cout << dq.size() << endl; 
    // check Empty 
    if(dq.empty()){
        cout << "Deque is empty" << endl; 
    } else {
        cout << "Deque is not empty" << endl; 
    }












    return 0; 
}
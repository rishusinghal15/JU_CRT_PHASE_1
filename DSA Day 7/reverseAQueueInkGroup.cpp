#include<iostream>
#include<stack>
#include<queue> 
using namespace std; 

void reverseInKGroup(queue<int>&q, int k, int unusedElementCount){
    // let's find out find whether we have any k elements to reverse or not 
    if(unusedElementCount >= k){
        // I have a k group to reverse
        // stack 
        // 1case m solve krunga
        stack<int> s; 
        for(int i=0; i<k;i++){
            int element = q.front();
            q.pop();
            s.push(element); 
        }
        for(int i=0;i<k;i++){
            int element = s.top(); 
            s.pop(); 
            q.push(element);    
        }

        // baaki kaam recursion krega
        reverseInKGroup(q,k,unusedElementCount-k);
    } 
    else {
        // I don't have a k group to reverse
        // as it is element ko push krna tha 
        for(int i=0;i<unusedElementCount;i++){
            int element = q.front(); 
            q.pop();
            q.push(element); 
        }
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


int main() {

    queue<int> q; 
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5); 
    q.push(6);
    q.push(7);
    q.push(8);

    int k = 3; 
    reverseInKGroup(q,k,q.size()); 
    printQueue(q); 


    return 0; 

}
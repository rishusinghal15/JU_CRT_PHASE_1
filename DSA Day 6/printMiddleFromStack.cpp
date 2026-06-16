#include<iostream>
#include<stack>
using namespace std;

void printMiddleFromStack(stack<int> &s, int count, int totalSize){
    // base case 
    if(count == totalSize/2){
        cout << s.top() << endl; 
        return ; 
    }

    // 1 case mera baaki recursion ka
    int val = s.top(); 
    s.pop(); 
    count++; 
    // recursion 
    printMiddleFromStack(s, count, totalSize);
    // backtracking 
    s.push(val); 
}

int main() {

    stack<int> s; 
    s.push(10);
    s.push(20); 
    s.push(30); 
    s.push(40); 
    s.push(50); 
    s.push(60);
    s.push(70); 
    int count = 0;
    int totalSize = s.size(); 
    printMiddleFromStack(s,count, totalSize); 

    return 0; 
}
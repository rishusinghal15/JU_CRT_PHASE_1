#include<iostream>
#include<stack>
using namespace std; 

void insertAtBottom(stack<int>&s, int val){
    // base case
    if(s.empty()){
        s.push(val); 
        return; 
    }

    // 1 case mera
    int topElement = s.top(); 
    s.pop(); 
    // baaki recursion 
    insertAtBottom(s, val); 
    // Backtrack 
    s.push(topElement);
}

void reverseStack(stack<int> &s){
    // base case
    if(s.empty()){
        return; 
    }

    // 1 case mera 
    int topElement = s.top(); 
    s.pop(); 
    // baaki recursion 
    reverseStack(s); 
    // backtrack
    insertAtBottom(s, topElement); 
}

void print(stack<int>&s){
    while(!s.empty()){
        cout << s.top() << " "; 
        s.pop(); 
    } cout << endl;
}


int main() {

    stack<int> s; 
    s.push(10); 
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    reverseStack(s);
    print(s); 
     


    return 0; 
}
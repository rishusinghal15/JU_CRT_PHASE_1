#include<iostream>
#include<stack>
using namespace std; 

int main(){
    stack<char> s; 
    string name = "amitwala";

    // Insertion of characters in the stack 
    for(int i=0; i<name.length(); i++){
        char ch = name[i]; 
        s.push(ch); 
    }

    // Retrieval of characters from Stack 
    while(!s.empty()){
        cout << s.top(); 
        s.pop(); 
    }

    return 0; 
}
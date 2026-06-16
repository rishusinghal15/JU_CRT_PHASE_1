#include<iostream>
#include<string>
using namespace std; 

int main(){
    string str = "Hello World"; 
    cout << str.length() << endl; 
    cout << str.size() << endl;
    cout << str.find("ll") << endl; 
    cout << str.replace(6,5,"Guide") << endl; 
    cout << str.append("!") << endl; 
    cout << str.substr(2,3) << endl; 
    cout << str.empty() << endl; 
    return 0; 
}
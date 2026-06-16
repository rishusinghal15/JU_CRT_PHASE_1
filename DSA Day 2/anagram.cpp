#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string a = "listen"; 
    string b = "silent"; 

    sort(a.begin(), a.end()); 
    sort(a.begin(), b.end());
    bool isTrue = (a==b); 
    cout << isTrue << endl; 
    return 0; 
}
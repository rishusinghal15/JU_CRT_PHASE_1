#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    string s = "racecar"; 
    bool bool_is_pal = (s == string(s.rbegin(), s.rend()));
    cout << bool_is_pal << endl;


    return 0; 
}
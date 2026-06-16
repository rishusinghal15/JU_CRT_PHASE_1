#include<iostream>
using namespace std; 

int factorial(int n){
    // basese  case
    if(n==0) return 1; 
    // 1 case khud solve krenge 
    int RecKaAns = factorial(n-1);
    // recursive call 
    int ans = n*RecKaAns; 
    return ans; 
}
int main(){
    cout << factorial(6) << endl; 
    return 0;
}
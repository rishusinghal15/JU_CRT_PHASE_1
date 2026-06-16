#include<iostream>
#include<limits.h>
using namespace std; 

void checkOdd(int arr[], int n, int index){
    // base case 
    if(index>=n){
        return ; 
    }
    // 1 case hum solve krenge 
    if(arr[index]&1){
        cout << arr[index]<< " "; 
    }
    // recursive call 
    checkOdd(arr,n,index+1); 
}

int main() {
    int arr[]= {10,27,3,1,5,7}; 
    int n = 6;
    int index = 0; 

    checkOdd(arr,n,index); 
    return 0; 

}
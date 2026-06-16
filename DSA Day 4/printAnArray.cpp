#include<iostream> 
using namespace std; 

void print(int arr[], int n, int index){
    // base case 
    if(index>=n){
        return; 
    }
    // 1 case solve krte h 
    cout << arr[index] <<" "; 
    // recursive call
    print(arr, n, index+1); 
}

// array->size->n, index->0 to n-1
void reversePrint(int arr[], int n){
    // base case 
    if(n==0){
        return; 
    }
    // 1 case solve krte h 
    cout << arr[n-1] <<" "; 
    // recursive call
    reversePrint(arr, n-1); 
}

int main(){

    int arr[]= {10,20,30,40,50};
    int n = 5; 
    int index=0; 
    print (arr,n,index); 
    cout << endl; 
    reversePrint(arr,n); 
    cout << endl; 

    return 0; 
}
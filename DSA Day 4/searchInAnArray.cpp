#include<iostream>
using namespace std; 

int search(int arr[], int n, int index, int target){
    // base case 
    if(index>=n) {
        return -1; 
    }
    // 1 case hme solve krna h 
    if(arr[index]==target){
        return index; 
    }
    // recursive call 
    int ans = search(arr, n,index+1,target); 
    return ans; 
}

int main(){

    int arr[]= {10,20,30,40};
    int n=4;
    int index=0; 
    int target = 30; 

    cout << search(arr, n,index,target) << endl; 


    return 0; 
}
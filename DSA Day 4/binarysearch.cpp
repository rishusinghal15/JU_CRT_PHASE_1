#include<iostream>
using namespace std; 

int binarySearch(int arr[], int s, int e, int target){

    // base case 
    if(s>e){
        return -1;  
    }

    // 1 case hum solve krenge 
    int mid = (s+e)/2; 
    if(arr[mid]==target){
        return mid; 
    }

    // recursion call 
    if(target>arr[mid]){
        return binarySearch(arr, mid+1, e, target); 
    } else {
        return binarySearch(arr, s, mid-1, target); 
    }
}

int main() {
    int arr[]= {10,20,30,40,50,60}; 
    int s=0; 
    int e= 6; 
    int target = 50;
    
    cout << binarySearch(arr,s,e,target); 

}
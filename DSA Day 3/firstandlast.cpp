#include<iostream> 
using namespace std; 

int first_Occurence(int arr[], int n, int target){
    int start = 0, end = n-1; 
    int ans=0; 
    while(start<=end){
        int mid = (start + end)/2; 
        if(arr[mid]==target){
            ans = mid; 
            end = mid - 1; 
        } else if(arr[mid]<target){
            start = mid + 1; 
        } else {
            end = mid-1; 
        }
    }
    return ans; 
}

int Last_Occurence(int arr[], int n, int target){
    int start = 0, end = n-1; 
    int ans=0;
    while(start<=end){
        int mid = (start + end)/2; 
        if(arr[mid]==target){
            ans = mid; 
            start = mid + 1;  
        } else if(arr[mid]<target){
            start = mid + 1; 
        } else {
            end = mid-1; 
        }
    }
    return ans; 
}

int main(){
    int arr[]= {1,2,2,3,3,3,4,5,6,6,7,7,8,8,8,9}; 

    cout << first_Occurence(arr, 16, 6) << endl; 
    cout << Last_Occurence(arr, 16, 6) << endl; 
    return 0; 
}
#include<iostream>
#include<limits.h>
using namespace std; 

void getMiniElement(int arr[], int n, int index, int &mini){
    // base case 
    if(index>=n){
        return ; 
    }
    // 1 case hum run krenge 
    mini = min(mini, arr[index]); 
    // recursive call
    getMiniElement(arr,n,index+1,mini); 
}

void getMaxiElement(int arr[], int n, int index, int &maxi){
    // base case 
    if(index>=n){
        return ; 
    }
    // 1 case hum run krenge 
    maxi = max(maxi, arr[index]); 
    // recursive call
    getMaxiElement(arr,n,index+1,maxi); 
}

int main() { 

    int mini = INT_MAX;
    int maxi = INT_MIN; 
    int arr[]= {10,20,30,2,4}; 
    int n = 5; 
    int index=0;

    getMiniElement(arr,n,index, mini); 
    cout << "Mini: " << mini << endl; 

    getMaxiElement(arr,n,index, maxi); 
    cout << "Maxi: " << maxi << endl; 


    return 0; 

}
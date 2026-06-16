#include<iostream>
using namespace std;
 
int main(){
    int arr[100], n,pos, element; 
    cout << "Enter the number of Elements: " ; 
    cin >> n; 

    cout << "Enter Array Elements: " << endl; 
    for(int i=0;i<n;i++){
        cin >> arr[i]; 
    }

    cout<< "Enter element to insert: " << endl;
    cin >> element; 

    cout << "Enter Position: " << endl; 
    cin >> pos; 

    for(int i=n;i>=pos;i--){
        arr[i] = arr[i-1];
    }
    arr[pos-1] = element; 
    n++; 

    cout<< "Array After Insertion: " << endl; 
    for(int i=0;i<n;i++){
        cout << arr[i]<<" "; 
    }

    return 0; 

}
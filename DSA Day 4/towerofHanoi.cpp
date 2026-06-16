#include<iostream>
using namespace std; 

void towerOfHanoi(int n, char source, char auxillary, char destination){
    if(n==1){
        cout << "Move disk " << n <<  " from " << source << "to" << destination << endl; 
        return; 
    }
    towerOfHanoi(n-1,  source, destination, auxillary); 
    cout << "Move disk " << n << " from " << source << "to" << destination << endl;
    towerOfHanoi(n-1,  auxillary, source, destination); 
}

int main(){

    int n=4; 
    towerOfHanoi(n,'A', 'B', 'C'); 
    return 0; 
}
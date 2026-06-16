#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std; 

void solve(int arr[], int n, vector<int>&ans){
    stack<int> s;
    s.push(-1);

    for(int i=n-1; i>=0; i--){
        int element = arr[i]; 
        while(s.top()>=element){
            s.pop(); 
        }
        // Yhaa prr joh stack ka top hoga woh hmesha 
        // chota hoga element se 
        ans.push_back(s.top()); 
        // push the element as well 
        s.push(element); 
    }
}


int main() {

    int arr[5] = {8,4,6,2,3}; 
    int n = 5; 

    vector<int>ans; 

    solve(arr,n, ans);
    reverse(ans.begin(), ans.end());  

    for(auto i: ans){
        cout << i << " "; 
    }



    return 0; 
}
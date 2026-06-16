#include <iostream>
using namespace std;

int bin_search(int arr[], int target, int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return bin_search(arr, target, mid + 1, high); // go right
    else
        return bin_search(arr, target, low, mid - 1); // go left
}

int main(){ 
    int arr[] = {2,7,12,19,25,34,43,55};
    int n = 8; 

    cout << bin_search(arr, 34, 0, 8) << endl;  // Output: 5
    // cout << bin_search(arr, 99, 0, 99) << endl;  // Output: -1

    return 0;
}
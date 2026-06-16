#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        } 
    } 
    return -1; 
}

int main(){ 
    int arr[] = {2,7,12,19,25,34,43,55};
    int n = 8; 

    cout << binary_search(arr, n, 34) << endl;  // Output: 5
    cout << binary_search(arr, n, 99) << endl;  // Output: -1

    return 0;
}
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int secondLargest(vector<int> &arr)
{

    if (arr.size() < 2)
    {
        cout << "Array must be at least two elements" << endl;
        return -1;
    }
    int first = INT_MIN, second = INT_MIN;
    for (int num : arr)
    {
        if (num > first)
        {
            second = first;
            first = num;
        }
        else if (num > second && num != first)
        {
            second = num;
        }
    }

    if (second == INT_MIN)
    {
        cout << "No second largest element" << endl;
        return -1;
    }
    return second;
}

int main()
{
    vector<int> arr = {12, 40, 1, 2, 3, 27, 34, 54};
    cout << "Second Largest: " << secondLargest(arr) << endl;
    return 0;
}
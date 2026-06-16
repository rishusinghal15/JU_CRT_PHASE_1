#include <iostream>
using namespace std;

double power(double x, int n)
{
    if (n == 0)
        return 1.0;

    // Half the prpblem
    double half = power(x, n / 2);

    if (n % 2 == 0)
    {
        return half * half;
    }
    else
    {
        return x * half * half;
    }
}

int main()
{
    cout << power(3,5); 
    return 0;
}
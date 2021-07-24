/*
    we have to calculate the power(a,n)
    i.e: we have to calculate a^n

   for that their is two method : 
    M1 (N): general method to just go through the a^n = a*a^(n-1)*....1
    M2 (logN): FastPower method         
*/

#include <iostream>
using namespace std;

int power(int a, int n)
{
    //Base case :
    if (n == 0)
    {
        return 1;
    }

    //rec case :
    return a * power(a, n - 1);
}

int fastPower(int a, int n)
{
    //base case :
    if (n == 0)
    {
        return 1;
    }

    //rec case :
    int smallAns = fastPower(a, n / 2);
    smallAns *= smallAns;

    if (n & 1)
    {
        return smallAns * a;
    }

    return smallAns;
}

int main()
{
    int n;
    cin >> n;

    int a;
    cin >> a;
    cout << power(a, n) << endl;
    cout << fastPower(a, n) << endl;

    return 0;
}
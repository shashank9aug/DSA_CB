/*
    multiply two number without using * operator

    a=5 b=2
    mul(a,b) = 5 + 5(2-1) = 5+5(1)=10

    a=10 b=3 
    mul(a,b) = 10 + 10(3-1) + 10(3-2) + 10(3-3) = 10 + ()
*/

#include <iostream>
using namespace std;

int multiplyNum(int num1, int num2)
{

    //rec case :
    // if (num1 < num2)
    // {
    //     return multiplyNum(num2, num1);
    // }

    //Base case :
    if(num1==0 or num2==0)
    {
        return 0;
    }

    else if (num2 != 0)
    {
        return (num1 + multiplyNum(num1, num2 - 1));
    }
}

int main()
{
    int num1, num2;
    cout << "Enter both the numbers : ";

    cin >> num1 ;
    cin>> num2 ;
    cout << "Multiplication of number : " << multiplyNum(num1, num2) << endl;

    return 0;
}
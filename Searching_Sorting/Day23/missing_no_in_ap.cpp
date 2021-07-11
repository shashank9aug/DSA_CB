// Input: A = 1, B = 3, C = 2
// Output: 1
// Explaination: 3 is the second term of the 
// sequence starting with 1 and having a common 
// difference 2.

/*
    
*/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int inSequence(int A, int B, int C)
    {
        // code here
        double a = A;
        double b = B;
        double c = C;
        double x = (b - a) / c + 1.0;

        //type cast
        int y = int(x);

        if (x < 1 || (x - y) > 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    Solution ob;
    cout << ob.inSequence(A, B, C) << endl;
    return 0;
}
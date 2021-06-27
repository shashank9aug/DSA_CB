// Input: 
// S = "0001010111"
// Output: 2

// Possibility1 : 0101010101  count1 =2
//possibility2 : 1010101010   count2=5


#include <bits/stdc++.h>
using namespace std;

int minFlips(string s);
int32_t main()
{
    string s;
    cout<<"Enter the input string : ";
    cin >> s;

    cout<<"min no of flips to make alternate binary string : " << minFlips(s) << endl;
}

int minFlips(string s)
{
    int count1 = 0, count2 = 0;
    int i = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 != 0 and s[i] == '0')
        {
            count1++;
        }
        if (i % 2 == 0 and s[i] == '1')
        {
            count1++;
        }
        if (i % 2 != 0 and s[i] == '1')
        {
            count2++;
        }
        if (i % 2 == 0 and s[i] == '0')
        {
            count2++;
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 != 0 and s[i] == '1')
        {
            count2++;
        }
        if (i % 2 == 0 and s[i] == '0')
        {
            count2++;
        }
    }

    return min(count1, count2);
}
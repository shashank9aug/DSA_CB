//Easy

//Convert roman numbers into numbers :
//Big->small  => Add.
//Small -> Big => Substract.

//compare always for str[i] and str[i+1].

#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main()
{
    string s;
    cout<<"Enter roman number : ";
    cin >> s;
    cout <<"corresponding numeric form : "<< romanToDecimal(s) << endl;
}

int num(char str)
{
    if (str == 'I')
    {
        return 1;
    }
    else if (str == 'V')
    {
        return 5;
    }
    else if (str == 'X')
    {
        return 10;
    }
    else if (str == 'L')
    {
        return 50;
    }
    else if (str == 'C')
    {
        return 100;
    }
    else if (str == 'D')
    {
        return 500;
    }
    else
    {
        return 1000;
    }
}

int romanToDecimal(string &str)
{
    // code here
    int res = 0;

    for (int i = 0; i < str.size(); i++)
    {
        int ans = num(str[i]);
        if (i + 1 < str.length())
        {
            int ans1 = num(str[i + 1]);
            if (ans >= ans1)
            {
                res += ans;
            }
            else
            {
                res += ans1 - ans;
                i++;
            }
        }
        else
        {
            res += ans;
        }
    }
    return res;
}

//smallest distinct window of char of string

// Input : "AABBBCBBAC"
// Output : 3
// Explanation : Sub-string -> "BAC"

//Approach : Naive
// we have to find all the distinct characters in string

//Then we have to find all the possible window of distict char
// ans will be min length of distict character

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findSubString(string str)
    {
        
    }
};

int main()
{
    string str;
    cin >> str;
    Solution ob;
    cout << ob.findSubString(str).size() << endl;
    return 0;
}
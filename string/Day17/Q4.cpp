//Remove consecutive duplicate character

//It will remove only consecutive duplicates

// Input:
// S = aabb
// Output:  ab
// Explanation: 'a' at 2nd position is
// appearing 2nd time consecutively.
// Similiar explanation for b at
// 4th position.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeConsecutiveCharacter(string str)
    {
        // code here.
        string ans = "";
        //check individual char
        char curr = str[0];
        ans += curr;
        for (int i = 1; i < str.size(); i++)
        {
            if (curr != str[i])
            {
                ans += str[i];
                curr = str[i];
            }
        }

        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution ob;
    cout << ob.removeConsecutiveCharacter(s) << endl;
}
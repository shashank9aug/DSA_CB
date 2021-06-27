// Input  : []][][
// Output : 2
// Explanation :
// First swap: Position 3 and 4
// [][]][
// Second swap: Position 5 and 6
// [][][]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int minimumNumberOfSwaps(string s)
    // {
    //     //Base case:
    //     int count = 0, ans = 0;
    //     if (s.size() % 2 != 0)
    //     {
    //         return -1;
    //     }
    //     else
    //     {
    //         for (int i = 0; i < s.size(); i++)
    //         {
    //             if (s[i] == '[')
    //             {
    //                 count++;
    //             }
    //             else
    //             {
    //                 if (!count)
    //                 {
    //                     ans++;
    //                     count++;
    //                 }
    //                 else
    //                 {
    //                     count--;
    //                 }
    //             }
    //         }
    //         return ans + count / 2;
    //     }
    // }

    //above will showing error on gfg submission because swapping should be in adjacent manner

    int minimumNumberOfSwaps(string s)
    {
        int ans = 0;
        int count1 = 0, count2 = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
            {
                ans += count2;
                if (count2 > 0)
                {
                    count2--;
                }
                else
                {
                    count1++;
                }
            }
            if (s[i] == ']')
            {
                if (count1 > 0)
                {
                    count1--;
                }
                else
                {
                    count2++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    string S;
    cin >> S;
    Solution ob;
    cout << ob.minimumNumberOfSwaps(S) << endl;
    return 0;
}
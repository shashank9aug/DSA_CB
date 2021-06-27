// N = 6
// arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
// Output: bbb
// Explanation: "bbb" is the second most
// occurring string with frequency 2.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string secFrequent(string arr[], int n)
    {
        //storing string and its frequency
        unordered_map<string, int> um;
        for (int i = 0; i < n; i++)
        {
            um[arr[i]]++;
        }

        //count two highest frequency string
        int count1 = 0, count2 = 0;
        for (auto it = um.begin(); it != um.end(); it++)
        {
            if (it->second > count1)
            {
                count2 = count1;
                count1 = it->second;
            }
            else if (it->second > count2 && it->second != count1)
            {
                count2 = it->second;
            }
        }

        //return string with occurence equal to count2
        for (auto it = um.begin(); it != um.end(); it++)
        {
            if (it->second == count2)
            {
                return it->first;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    Solution ob;
    cout << ob.secFrequent(arr, n) << endl;
}

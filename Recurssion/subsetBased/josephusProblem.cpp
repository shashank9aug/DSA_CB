/*
    Problem : Josephus was standing with other people in circle in which every 7th people
    will die and at the end single person will remain in circle that person will do sucide 
    
    we have to find in group of people where josephus should stand so that he will left alone at the end

    number of people = 40 
    josephus will stand at 24th position so that he will be left at the end.
*/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int killPerson(vector<int> &v, int k, int index)
    {
        //Base case :
        if (v.size() == 1)
        {
            return v[0];
        }
        else
        {
            index = (index + k) % v.size();
            v.erase(v.begin() + index);
            return killPerson(v, k, index);
        }
    }

    int safePos(int n, int k)
    {
        // code here
        vector<int> v;
        for (int i = 1; i <= n; ++i)
        {
            v.push_back(i);
        }

        return killPerson(v, k - 1, 0);
    }
};

int main()
{
    int n, k;

    cin >> n >> k;

    Solution ob;
    cout << ob.safePos(n, k) << endl;
    return 0;
}
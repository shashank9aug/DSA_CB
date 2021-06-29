//check if two given strings are isomorphic to each other

/*
    isomorphic : Two strings str1 and str2 are called isomorphic
                if there is a one to one mapping possible for every character of
                str1 to every character of str2 while preserving the order. 

*/

// C++ program to check if two strings are isomorphic
#include <iostream>
#include <string.h>
using namespace std;

class Solution
{
public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        //Base case : size of both the string should be equal
        if (str1.length() != str2.length())
        {
            return false;
        }

        int h1[26] = {0};
        int h2[26] = {0};

        for (int i = 0; i < str1.length(); i++)
        {
            if (h1[str1[i] - 'a'] == 0)
            {
                if (h2[str2[i] - 'a'] == 0)
                {
                    h2[str2[i] - 'a']++;
                    h1[str1[i] - 'a'] = str2[i];
                }
                else
                {
                    return false;
                }
            }
            else if (h1[str1[i] - 'a'] != str2[i])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    Solution obj;
    cout << obj.areIsomorphic(s1, s2) << endl;

    return 0;
}
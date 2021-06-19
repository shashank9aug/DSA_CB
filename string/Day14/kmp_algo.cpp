//KMP Algorithm

// Pattern searching is an important problem in computer science. When we do search
// for a string in notepad/word file or browser or database,
// pattern searching algorithms are used to show the search results.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    Compute temporary array to maintain size of suffix which is same as prefix
    Time/space complexity is O(size of pattern)
*/
vector<int> computeTemproryArray(string pattern)
{
    vector<int> lps;
    int index = 0;

    for (int i = 0; i < pattern.size();)
    {
        if (pattern[i] == pattern[index])
        {
            lps[i] = index + 1;
            index++;
            i++;
        }
        else
        {
            if (index != 0)
            {
                index = lps[index - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool kmp(string txt, string pattern)
{
    vector<int> lps = computeTemproryArray(pattern);

    int i = 0;
    int j = 0;

    while (i < txt.size() && j < pattern.size())
    {
        if (txt[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    if (j == pattern.size())
    {
        return true;
    }
    return false;
}

int main()
{
    string txt;
    cout << "Enter the text string : ";
    // cin.getline(txt,100,'\0');
    cin >> txt;

    string pattern;
    cout << "Enter pattern string need to search : ";
    cin >> pattern;

    cout << kmp(txt, pattern) << endl;

    return 0;
}
//Longest common prefix :

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// showing error as segmentation fault

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//find the minimum length of strings in array
int find_minLength(vector<string>&str)
{
    int min = str[0].length();

    for (int i = 1; i < str.size(); i++)
    {
        if (str[i].length() < min)
        {
            min = str[i].length();
        }
    }

    return min;
}

//we are taking array of strings in 2d array form :
//maching row wise every characters of words : 

string common_prefix(vector<string>&words)
{
    int min_len = find_minLength(words);
    char curr_common;
    string prefix_common = "";
    for (int j = 0; j < min_len; j++)
    {
        curr_common = words[0][j];
        for (int i = 0; i < words.size(); i++)
        {
            if(words[i][j]!=curr_common){
                return prefix_common;
            }
        }
        prefix_common.push_back(curr_common);
    }
    return prefix_common;
}

int main()
{
    vector<string> words;
    cout << "Enter words : ";
    for (int i = 0; i < 5; i++)
    {
        cin >> words[i];
    }

    string ans=common_prefix(words);

    if(ans.length()){
        cout<<"Prefix common : "<<ans<<endl;
    }
    else{
        cout<<"Their is no prefix common items"<<endl;
    }

    return 0;
}
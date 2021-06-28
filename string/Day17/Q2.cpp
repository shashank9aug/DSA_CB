//Print Anagram together

//Anagram : set of characters should be same in string
// eg : act cat tac

// Input:
// N = 5
// words[] = {act,god,cat,dog,tac}
// Output:
// god dog
// act cat tac
// Explanation:
// There are 2 groups of
// anagrams "god", "dog" make group 1.
// "act", "cat", "tac" make group 2.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<string>> print_anagram(vector<string> &str);

vector<vector<string>> print_anagram(vector<string> &str){
    map<string,vector<string>>mp;

    //Iterate over the given str
    for(int i=0;i<str.size();i++){
        string s=str[i];
        //sort the each individual item lexographically
        sort(s.begin(),s.end());

        // store it into map  : m[s] -> single item which will used to compare
        mp[s].push_back(str[i]);
    }

    //take 2d vector to store grouped anagrams of size map
    vector<vector<string>>ans(mp.size());

    int idx=0;
    //itereate over map and store grouped string
    for(auto i:mp){
        auto x=i.second;

        for(int j=0;j<x.size();j++){
            ans[idx].push_back(x[j]);
        }
        idx++;
    }
    return ans;
}

int main(){
     int n;
    cin >> n;
    vector<string> string_list(n);
    for (int i = 0; i < n; ++i)
        cin >> string_list[i];
    vector<vector<string>> result = print_anagram(string_list);
    sort(result.begin(), result.end());

    cout<<"Group of Anagrams are : ";
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

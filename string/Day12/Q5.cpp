//Permutation of given string : 

// Input: ABC
// Output:
// ABC ACB BAC BCA CAB CBA
// Explanation:
// Given string ABC has permutations in 6 
// forms as ABC, ACB, BAC, BCA, CAB and CBA 

//total number of combinations that will generate of given string  :  N!  (N=size of str)

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
using namespace std;


void permute(string &s, int i, vector<string>&ans ) {
    if (i == s.size() - 1) {
        ans.push_back(s);
        return;
    }
    for (int j = i; j < s.size(); j++) {
        swap(s[i], s[j]);
        permute(s, i + 1, ans);
        swap(s[i], s[j]);
    }
    return;
}

vector<string>permutation_str(string S)
{
    vector<string>ans;
    
    permute(S, 0, ans);
    
    sort(ans.begin(), ans.end());
    
    return ans;
}

int main(){
    string str;
    cout<<"Enter the input string : ";
    cin>>str;

    vector<string>ans=permutation_str(str);

    cout<<"Permutation of string : ";
    for(auto i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
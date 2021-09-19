/*
    $ ./a.exe
    aabacbebebe
*/


#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution{
  public:
    int longestKSubstrUnique(string s) {
        // your code here
        int i=0,j=0;
        int mx=-1;
        unordered_map<char,int>mp;
        mp.clear();
        
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()>(j-i+1)){
                j++;
            }
            else if(mp.size()==(j-i+1)){
                mx=max(mx,(j-i+1));
                j++;
            }
            else if(mp.size()<(j-i+1)){
                while(mp.size()<(j-i+1)){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};


int main(){
    string str;
    cin>>str;


    Solution s;
    cout<<s.longestKSubstrUnique(str)<<endl;

    return 0;
}
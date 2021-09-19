/*
    $ ./a.exe
    aabacbebebe
    3
    7
*/


#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        // your code here
        int i=0,j=0;
        int mx=-1;
        unordered_map<char,int>mp;
        mp.clear();
        
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()<k){
                j++;
            }
            else if(mp.size()==k){
                mx=max(mx,(j-i+1));
                j++;
            }
            else if(mp.size()>k){
                while(mp.size()>k){
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

    int k;
    cin>>k;

    Solution s;
    cout<<s.longestKSubstr(str,k)<<endl;

    return 0;
}
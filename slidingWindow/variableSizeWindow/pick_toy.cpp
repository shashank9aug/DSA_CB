/*
Problem Description: No Where, it was an interview problem

John is at a toy store help him pick maximum number of toys. He can only select in a continuous manner and he can select only two types of toys.


Example:
Input:
1
abaccab

*/

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
    int longestKSubstr(string s) {
        // your code here
        int i=0,j=0;
        int mx=-1;
        unordered_map<char,int>mp;
        mp.clear();
        
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()<2){
                j++;
            }
            else if(mp.size()==2){
                mx=max(mx,(j-i+1));
                j++;
            }
            else if(mp.size()>2){
                while(mp.size()>2){
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
    cout<<s.longestKSubstr(str)<<endl;

    return 0;
}
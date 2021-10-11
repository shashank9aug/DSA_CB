/*
Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression 
so that the value of expression evaluates to true.

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

Goal : partition expression such that it results into true expression
*/

#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;


class Solution{
private:

//defining map : (i+' '+j+' '+isTrue) as key and its corresponding value.

unordered_map<string,int> mp;
int solve(string st,int i,int j,bool isTrue) {
	if(i>j) return 0;
	if(i==j) {
		if(isTrue) {
    		return st[j]=='T';
		}else {
			return st[j]=='F';
		}
	}
	string key = to_string(i);
	key.push_back(' ');
	key.append(to_string(j));
	key.push_back(' ');
	key.append(to_string(isTrue));
    if(mp.find(key) != mp.end()){
        return mp[key];
    }
	int answer=0;
	for(int k=i+1;k<j;k+=2) {
		int lt=solve(st,i,k-1,true);
		int lf=solve(st,i,k-1,false);
		int rt=solve(st,k+1,j,true);
		int rf=solve(st,k+1,j,false);
			
		if(st[k] == '&') {
			if(isTrue) {
				answer+=lt*rt;
			}else {
				answer+=lt*rf+lf*rt+lf*rf;
			}
			}else if(st[k] == '^') {
	    		if(isTrue) {
	    			answer+=lt*rf+lf*rt;
				}else {
					answer+=lt*rt+lf*rf;
				}
			}else if(st[k] == '|') {
				if(isTrue) {
					answer+=lt*rt+lt*rf+lf*rt;
				}else {
					answer+=lf*rf;
				}
			}
		}
	mp[key] = answer%1003;
	return answer%1003;
}
public:
int countWays(int N, string S){
    return solve(S,0,N-1,true);
}
};

int main(){
    int n;
    cin>>n;
    
    string s;
    cin>>s;
    Solution sol;
    cout<<sol.countWays(n,s)<<endl;

    return 0;
}

// Stock span problem : variation of Nearest greater to left i.e: Q1 .

// Input: 
// N = 6, price[] = [10 4 5 90 120 80]
// Output:
// 1 1 2 4 5 1
// Explanation:
// Traversing the given input span for 10 
// will be 1, 4 is smaller than 10 so the 
// span will be 1, 5 is greater than 4 so 
// the span will be 2 and so on. Hence, the 
// output will be 1 1 2 4 5 1.



#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
        vector<int>ans;
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            if(st.size()==0){
                ans.push_back(-1);
            }
            else if(st.size()>0 && st.top().first>price[i]){
                ans.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first<=price[i]){
                while(st.size()>0 && st.top().first<=price[i]){
                    st.pop();
                }
                if(st.size()==0){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(st.top().second);
                }
            }
            st.push({price[i],i});
        }
       for(int i=0;i<ans.size();i++){
           ans[i]=i-ans[i];
       }
       return ans;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
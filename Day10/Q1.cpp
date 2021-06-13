// Function to find the next greater element for each element of the array in right.

// Input: 
// N = 4, arr[] = [1 3 2 4]
// Output:
// 3 4 4 -1
// Explanation:
// In the array, the next larger element 
// to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
// since it doesn't exist, it is -1.

//Basically we are finding next greater element for each element in right 


#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, long long n){
        // Your code here
        vector<long long>v;
        stack<long long>st;
        
        for(long long i=n-1;i>=0;i--){
            if(st.size()==0){
                v.push_back(-1);
            }
            else if(st.size()>0 and st.top()>arr[i]){
                v.push_back(st.top());
            }
            else if(st.size()>0 and st.top()<=arr[i]){
                while(st.size()>0 and st.top()<=arr[i]){
                    st.pop();
                }
                if(st.size()==0){
                    v.push_back(-1);
                }
                else{
                    v.push_back(st.top());
                }
            }
            st.push(arr[i]);
        }
        reverse(v.begin(),v.end());
        
        return v;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
} 
// Function to find the next/nearest smallest element for each element of the array in left.

// Input: 
// N = 4, arr[] = [1 3 2 4]
// Output:
// -1 1 1 2


//Basically we are finding next smallest element for each element in left 


#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector< int> nextLargerElement(vector< int> arr,int n){
        // Your code here
        vector< int>v;
        stack<int >st;
        
        for(int i=0;i<n;i++){
            if(st.size()==0){
                v.push_back(-1);
            }
            else if(st.size()>0 and st.top()<arr[i]){
                v.push_back(st.top());
            }
            else if(st.size()>0 and st.top()>=arr[i]){
                while(st.size()>0 and st.top()>=arr[i]){
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
        
        return v;
    }
};


int main()
{
    int t;
    cout<<"Enter the no of test case : ";
    cin>>t;
    while(t--)
    {
        
        int n;
        cout<<"Enter the size of array: ";
        cin>>n;
        vector<int > arr(n);
        cout<<"Enter the array elements : ";
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <int > res = obj.nextLargerElement(arr, n);
        for (int  i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
} 
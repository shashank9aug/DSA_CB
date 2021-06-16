// Input:
//       N = 5, S = 12
// Output:
//       93000
// Explanation:
//      Sum of elements is 12. Largest possible 
//      5 digit number is 93000 with sum 12.



#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        // Your code here
        //Base case
        int max_sum=0;
        for(int i=1;i<=n;i++){
            max_sum+=9;
        }
        if(max_sum<sum){
            return "-1";
        }
        int val=0;
        string str(n,'0');
        for(int i=0;i<n;i++){
            if(sum>9){
                val=9;
                sum-=9;
            }
            else{
                val=sum;
                sum=0;
            }
            str[i]=val + '0';
        }          
        
        return str;
    }
};

int main()
{
	int t;
    cout<<"Enter the number test cases : ";
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
        cout<<"Enter the value of number of digits and digit sum : ";
		cin>>n>>sum;
		
        Solution obj;
        //function call
        
		cout<<"largest number with given sum : "<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
} 
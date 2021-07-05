//output the product array

// input : 1,2,3,4,5
//  output : 120,60,40,30,24

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index

    //M1 : O(N) and O(1) But using division operator 
   /*
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {

        //code here
        //calculate product of entire element avoiding zeroes
        int count0 = 0;
        long long int product = 1;

        //count the zeroes in array :
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                product *= nums[i];
            }
            else
            {
                count0++;
            }
        }

        vector<long long int> ans(n, 0);
        //if their is any zero element
        if (count0 == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == 0)
                {
                    ans[i] = product;
                    break;
                }
            }
        }
        //if their is no any zero
        else if (count0 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                ans[i] = product / nums[i];
            }
        }
        return ans;
    }
    */

    //M2 : we can calculate this without using multiplication operator : 

    //calculate two cumulative product array i.e : left and right
  /*  wrong ans :   
    vector<long long int> productExceptSelf(vector<long long int>& nums,int n) {
        //T.c: o(N)  and space : O(N) without using division opertor
        vector<long long int>op(n);
        vector<long long int>left(n);
        vector<long long int>right(n); 
        //product variable
        int product=1;
        //create left cumulative
        for(int i=0;i<nums.size();i++){
            product = product*nums[i];
            left.push_back(product);
        }
        
        //make product=1;
        product=1;
        // traverse from back to maintain right array
        for(int i=nums.size()-1;i>=0;i--){
            product*=nums[i];
            right.push_back(product);
        }
        
        //Base case output:
        op.push_back(right[1]);

        for(int i=1;i<nums.size()-1;i++){
            op.push_back(left[i-1]*right[i+1]);
        }

        op.push_back(left[nums.size()-2]);
        
        return op;
    }
    */


    //M3 : we can calculate without extra space and division operator:
    vector<long long int> productExceptSelf(vector<long long int>& nums,int n) {
        //T.c: o(N)  and space : O(1) without using division opertor
        vector<long long int>op;
        
        //product variable
        int product=1;
        //create left cumulative
        for(int i=0;i<nums.size();i++){
            product = product*nums[i];
            op.push_back(product);
        }
        
        //make product=1;
        product=1;
        // traverse from back to maintain right array
        for(int i=nums.size()-1;i>0;i--){
            op[i]=op[i-1]*product;
            product*=nums[i];
        }
        //for 0th element op will be product
        op[0]=product;
        
        return op;
    }
    
};

int main()
{

    int n; // size of the array
    cin >> n;
    vector<long long int> arr(n), vec(n);

    for (int i = 0; i < n; i++) // input the array
    {
        cin >> arr[i];
    }
    Solution obj;
    vec = obj.productExceptSelf(arr, n); // function call

    for (int i = 0; i < n; i++) // print the output
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
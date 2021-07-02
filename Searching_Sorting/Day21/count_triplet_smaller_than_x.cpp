// Input: N = 4, X = 2
// arr[] = {-2, 0, 1, 3}
// Output:  2
// Explanation: Below are triplets with 
// sum less than 2 (-2, 0, 1) and (-2, 0, 3)

//T.C : O(N^2)


#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    //showing more TLE

    // long long countTriplets(long long arr[], int n, long long sum)
    // {
    //     long long count=0;
    //    for (int i = 0; i < n - 1; i++) {
    //       for (int j = i + 1; j < n; j++) {
    //           for(int k=j+1;k<=n;k++){
    //                if ((arr[i] + arr[j]+arr[k]) < sum) {
    //                    count+=1;
    //                }
    //         }
    //     }
    //  }
    // return count;

    // }

    //optimised code :

    long long countTriplets(long long arr[], int n, long long sum)
    {
        // Your code goes he
        long long count = 0;
        sort(arr, arr + n);

        for (int i = 0; i < (n - 2); i++)
        {
            int j = i + 1, k = n - 1;

            while (j < k)
            {
                if (arr[i] + arr[j] + arr[k] >= sum)
                {
                    k--;
                }
                else
                {
                    count += (k - j);
                    j++;
                }
            }
        }

        return count;
    }
};

int main()
{

    int n;
    long long sum;
    cin >> n >> sum;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution ob;
    cout << ob.countTriplets(arr, n, sum);

    cout << "\n";

    return 0;
}
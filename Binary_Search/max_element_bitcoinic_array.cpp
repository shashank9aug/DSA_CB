/*
    Bitonic array : Array whose elements are increasing upto max element and 
                    then decreasing
            we have to find that max element upto which array elements are increasing
            after that decreasing        

    Input: 
    n = 5
    arr[] = {1, 45, 47, 50, 5}
    Output: 50
    Explanation: Maximum element is 50.

*/


#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaximum(int arr[], int n)
    {
        // code here
        if (n == 1)
            return 0;

        int start = 0;
        int end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (mid == 0)
            {
                if (arr[mid] > arr[mid + 1])
                    return arr[mid];
            }
            else if (mid == (n - 1))
            {
                if (arr[mid] > arr[mid - 1])
                    return arr[mid];
            }
            else if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return arr[mid];

            if (arr[mid + 1] > arr[mid])
                start = mid + 1;

            else
                end = mid - 1;
        }
        return -1;
    }
};


int main()
{
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.findMaximum(arr, n);
    cout << ans << "\n";
    return 0;
}
// Input:
// arr1[] = {2, 3, 6, 7, 9}
// arr2[] = {1, 4, 8, 10}
// k = 5
// Output:
// 6
// Explanation:
// The final sorted array would be -
// 1, 2, 3, 4, 6, 7, 8, 9, 10
// The 5th element of this array is 6.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //we can optimise this furthur sorting only upto k no of elements but not even store them
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        //Merge two sorted array
        //using two pointer approach
        int i = n - 1;
        int j = 0;
        // sort the array internally
        while (i >= 0 && j < m)
        {
            if (arr1[i] >= arr2[j])
            {
                swap(arr1[i], arr2[j]);
                i--;
                j++;
            }
            else
            {
                break;
            }
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);

        if (k <= n)
        {
            return arr1[k - 1];
        }
        else
        {
            return arr2[k - n - 1];
        }
    }
};

int main()
{

    int n, m, k;
    cin >> n >> m >> k;
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    Solution ob;
    cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
    return 0;
}
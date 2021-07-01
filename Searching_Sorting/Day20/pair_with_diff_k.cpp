//we have to find if their is an pair if diff == k return true else false

//T.C should be : O(N*LogN);

#include <bits/stdc++.h>

using namespace std;

bool findPair(int arr[], int size, int n);

int main()
{
    int l, n;
    cin >> l >> n;
    int arr[l];
    for (int i = 0; i < l; i++)
        cin >> arr[i];
    if (findPair(arr, l, n))
        cout << 1 << endl;
    else
        cout << "-1" << endl;

    return 0;
}

bool findPair(int arr[], int size, int n)
{
    //code
    sort(arr, arr + size);
    //apply binary search :
    int low = 0, high = 1;
    while (low < size and high < size)
    {
        int diff = abs(arr[high] - arr[low]);
        if (low != high and diff == n)
        {
            return true;
        }
        else if (diff < n)
        {
            high++;
        }
        else
        {
            low++;
        }
    }
    return false;
}
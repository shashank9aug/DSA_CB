//kth smallest number :

/*
input : 
 t--
    N
    arr (contains two elements i.e: range of elements)
    k 

    1
    1 3
    1 5
    1
    3
    6
output :
    arr[k-1]
*/

#include <iostream>
#include <algorithm>
using namespace std;

int kth_smallest(int n, int arr[], int k)
{
    //check that array is sorted or not :
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        if (arr[i] > arr[j] and (j < n))
        {
            return -1;
        }
    }

    return arr[k - 1];
}

int main()
{
    int t;
    cout << "Enter number of test cases : ";
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int k;
        cin >> k;

        cout << "Kth smallest item in array : " << kth_smallest(n, arr, k) << endl;
    }
    return 0;
}
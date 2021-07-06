/*
    0  1  2  3  4  5 6 
    2,4,10,10,10,18,20

    start=0;
    end = 6
    mid=3

    first occurrence = 2
*/    

#include <iostream>
#include <algorithm>
using namespace std;

//for ascending order array

int first_occurrence(int n, int arr[], int key)
{
    int start = 0;
    int end = n - 1;
    int ans=0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            ans=mid;
            end=mid-1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n;
    cout << "Eneter the number of elements in array : ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements  : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Eneter the key need to search : ";
    cin >> key;
    cout <<first_occurrence(n, arr, key) << endl;

    return 0;
}
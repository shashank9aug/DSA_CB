// Array is given in sorted order

//find the index of given element position otherwise if not present return -1;

#include <iostream>
#include <algorithm>
using namespace std;

//for ascending order array

int binarySearch(int n, int arr[], int key)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid;
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

    return -1;
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
    cout << binarySearch(n, arr, key) << endl;

    return 0;
}
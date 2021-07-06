/*
    0  1  2  3  4  5 6 
    2, 4,10,10,10,18,20

    start=0;
    end = 6
    mid=3

    last occurrence =4 
*/

/*

Eneter the number of elements in array : 5
Enter array elements  : 2 4 10 10 10 
Eneter the key need to search : 10
4

*/

#include <iostream>
#include <algorithm>
using namespace std;

//for ascending order sorted array

int last_occurrence(int n, int arr[], int key)
{
    int start = 0;
    int end = n - 1;
    int ans = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
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
    cout << last_occurrence(n, arr, key) << endl;

    return 0;
}
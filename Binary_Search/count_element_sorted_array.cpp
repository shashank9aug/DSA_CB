/*
    0  1  2  3  4  5 6 
    2,4,10,10,10,18,20

    start=0;
    end = 6
    mid=3

    first occurrence = 2
    last occurrence = 4
    count = 4-2+1 = 3 
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
    int first=first_occurrence(n, arr, key);
    int last = last_occurrence(n,arr,key);
    
    cout<<"total count of key : "<<(last-first+1)<<endl;

    return 0;
}
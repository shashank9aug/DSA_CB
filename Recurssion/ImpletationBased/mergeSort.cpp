/*
    Merge sort : we will divide the array about midPoint then,
    sort both the part separately and again merge both the subarray separetly

    - we are using extra space for merging the subarrays
*/

#include <iostream>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;

    int i = s;
    int j = mid + 1;
    int k = s;

    int temp[100];

    while (i <= mid and j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= e)
    {
        temp[k++] = arr[j++];
    }

    //we need to copy all element to original array :
    for (int i = s; i <= e; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int start, int end)
{
    //Base case :
    if (start >= end)
    {
        return;
    }

    //divide : about midpoint
    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    //merge both the parts :
    merge(arr, start, end);
}

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s = 0;
    int e = n - 1;
    mergeSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }
    return 0;
}
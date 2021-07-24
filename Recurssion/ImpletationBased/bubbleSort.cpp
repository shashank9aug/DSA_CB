/*
    Bubble sort : sorting technique which will follow O(n^2) method

    we have to use recurssion.

*/

#include <iostream>
using namespace std;

//Partially recurssive function :
void bubbleSort(int arr[], int n)
{
    //Base case :
    if (n == 1)
    {
        return;
    }

    //rec case :
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    //call for first n-1 elements :
    bubbleSort(arr, n - 1);
}

//completely recurssive function :
void bubbleSortRecurssive(int arr[], int j, int n)
{
    //Base case :
    if (n == 1)
    {
        return;
    }

    //checking for the number of passes :
    if (j == n - 1)
    {
        return bubbleSortRecurssive(arr, 0, n - 1);
    }

    if (arr[j] > arr[j + 1])
    {
        swap(arr[j], arr[j + 1]);
    }
    return bubbleSortRecurssive(arr, j + 1, n);
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

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }
    return 0;
}
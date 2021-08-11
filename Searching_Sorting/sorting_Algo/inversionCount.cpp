/*
    we have to count the number of inversion we can make if(arr[i]>arr[j] and i>j)

    we can do this using merge sort

    all the inversions count will come from merge function.
*/

#include <iostream>
using namespace std;

int merge(int arr[], int s, int e)
{
    int mid=s+(e-s)/2;

    int i=s;
    int j=mid+1;
    int k=s;

    int temp[100];
    int count=0;
    //two pointer approach to merge :
    while(i<=mid and j<=e){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            count+=mid-i+1;
        }
    }

    while(i<=mid){
        temp[k++]=arr[i++];
    }

    while(j<=e){
        temp[k++]=arr[j++];
    }

    for(int i=s;i<=e;i++){
        arr[i]=temp[i];
    }

    return count;
}

int countInversion(int arr[], int s, int e)
{
    //Base case :
    if (s >= e)
    {
        return 0;
    }

    //Merge Sort :
    int mid = s + (e - s) / 2;
    int x = countInversion(arr, s, mid);
    int y = countInversion(arr, mid + 1, e);

    //counting cross inversion : 
    int z = merge(arr, s, e);

    return (x + y + z);
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
    int start = 0, end = n - 1;
    cout << "Inversion count : " << countInversion(arr, start, end) << endl;
}
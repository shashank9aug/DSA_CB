#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int min_swaps(int arr[], int n)
{
    // Code here
    //store number and its position in vector of pair
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = {arr[i], i};
    }
    //sorting the vector and its initial position will change accordingly
    sort(v.begin(), v.end());

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        //if postion of element not changed after passing through sort function 
        if (v[i].second == i)
        {
            continue;
        }
        else
        {
            count++;
            //swap to it's original position
            swap(v[i], v[v[i].second]);
            i--;
        }
    }
    return count;
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

    cout << "Minimum no of swaps : " << min_swaps(arr, n) << endl;

    return 0;
}
/*
    floor of element in sorted array is greater element smaller than element

    arr[]={1,2,3,4,8,10,10,12,19}
    key = 5
    floor = 4;

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> arr, long long N, long long k)
    {

        // Your code here
        int start = 0;
        int end = N - 1;
        //to maintain maximum among smallest :
        int res = -1;
        while (start <= end)
        {
            long long int mid = start + (end - start) / 2;
            if (arr[mid] == k)
            {
                return mid;
            }
            else if (arr[mid] < k)
            {
                res = mid;
                start = mid + 1;
            }
            else if (arr[mid] > k)
            {
                end = mid - 1;
            }
        }
        return res;
    }
};

int main()
{

    long long n;
    cout << "Enter no of elements in vector : ";
    cin >> n;
    long long x;
    cout << "Enter the element need to find for floor : ";
    cin >> x;

    vector<long long> v;
    cout<<"Enter vector elements : ";
    for (long long i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        v.push_back(temp);
    }
    Solution obj;
    cout << obj.findFloor(v, n, x) << endl;

    return 0;
}
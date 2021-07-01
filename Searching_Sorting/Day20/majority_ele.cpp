//Find majority element :

/*
    case 1 : 
        input: 5
            {1,3,3,3,2}
        output : 3

    case 2 :
        input : 3
            {1,2,3}
        output : -1         

*/

//Implementation of Moore Voting algorithm

/*

    case 1: their must be an majority element.
    case 2: array may or may not have majority element.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int n)
    {

        // your code here
        int ele = arr[0];
        int count = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] == ele)
            {
                count++;
            }
            else
            {
                count--;
                if (count == 0)
                {
                    ele = arr[i];
                    count++;
                }
            }
        }

        int count_ele = 0;
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == ele)
            {
                count_ele++;
            }
            if (count_ele > (n / 2))
            {
                ans = true;
                break;
            }
            else
            {
                ans = false;
            }
        }

        if (ans)
        {
            return ele;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution obj;
    cout << obj.majorityElement(arr, n) << endl;
}
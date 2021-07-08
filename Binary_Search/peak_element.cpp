/*
    peak element: element which is greater from both of its neighbour

    Input: nums = [1,2,3,1]
    Output: 2
    Explanation: 3 is a peak element and your function should return the index number 2.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (mid == 0)
            {
                if (nums[mid] > nums[mid + 1])
                    return 0;
            }
            else if (mid == (nums.size() - 1))
            {
                if (nums[mid] > nums[mid - 1])
                    return mid;
            }
            else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;

            if (nums[mid + 1] > nums[mid])
                start = mid + 1;

            else
                end = mid - 1;
        }
        return -1;
    }
};

int main()
{
    int n;
    cout << "Enter number of element : ";
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution ob;

    cout << ob.findPeakElement(nums) << endl;

    return 0;
}
/*
    Very Important problem : 

    Given : arr[] => size = n;
            k = no of student to allocate page
    condition : 
        1: single book must be allocate to single student
        2: every student must have atleast one book
        3: book allocation must be in contiguous fashion     

    input: arr[] = {10,20,30,40}
            n=4;
            k=2;

    output : minimum(no of pages) which student will get to read
        -> 75
          s1=10+20+30
          s2=40
        -> 62
          s1=10+20+30
          s2=40
        -> 60
          s1=10+20+30
          s2=40
      minimum = 60 
    output = 60;                  
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //validate the number of page allocate to every student
    bool isValid(int arr[], int n, int m, int mid)
    {
        int student = 1, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                student++;
                sum = arr[i];
            }
            if (student > m)
            {
                return false;
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m)
    {
        if (n < m)
        {
            return -1;
        }
        //code here
        //calculate maximum pages in among all books
        int max_page = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            max_page = max(max_page, arr[i]);
        }

        //calculate sum of all the pages among all the boooks
        int page_sum = 0;
        for (int i = 0; i < n; i++)
        {
            page_sum += arr[i];
        }

        //allocate start as max_page and end as sum_of_all_page
        int start = max_page, end = page_sum;

        int ans = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (isValid(arr, n, m, mid) == true)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cout<<"Enter number of books : ";
    cin >> n;
    int A[n];
    cout<<"Enter number of pages in each book : ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int m;
    cout<<"Enter number of student : ";
    cin >> m;
    Solution ob;
    cout << ob.findPages(A, n, m) << endl;
    return 0;
}
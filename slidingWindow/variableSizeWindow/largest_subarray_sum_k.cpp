#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int solve(vector<int> &A, const int &k) {
	int n = A.size();
	int i = 0, j = 0, sum = 0;
	int mx = INT_MIN;
	while (j < n) {
		//calculation : 
        sum += A[j];

		if (sum < k) {
			j++;
		} 
        else if (sum == k) {
			mx = max(mx, j - i + 1);
			j++;
		} 
        else if (sum > k) {
            //ans from calculation : 
        	while (sum > k) {
				sum = sum - A[i];
				i++;
			}
            //slide the window :
			j++;
		}
	}
	return mx;
}

int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

	vector<int> A;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        A.push_back(d);
    }

	int sum;
    cout<<"Max sum : ";
    cin>>sum;

	cout << solve(A, sum);
	return 0;
}
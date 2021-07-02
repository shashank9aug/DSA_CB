//find all pair of 4 number whose sum equal to fiven k

// Input:
// N = 5, K = 3
// A[] = {0,0,2,1,1}
// Output: 0 0 1 2 $
// Explanation: Sum of 0, 0, 1, 2 is equal
// to K.


/* N = 7, K = 23
 A[] = {10,2,3,4,5,7,8}
    10+2+3+4=17
    10+2+3+5=20
    10+2+3+7=22
    10+2+3+8=23(push in vector)
    
    2+3+4+5=

*/

#include<bits/stdc++.h>
using namespace std;





int main(){
    int n;
    cout<<"Enter the length of array : ";
    cin>>n;

    int k;
    cout<<"Enter the value of k : ";
    cin>>k;

    int arr[n];
    cout<<"Enter the elements in array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    pair_sum(n,arr,k);

}

/*
    Leetcode : https://leetcode.com/problems/k-th-symbol-in-grammar/

    Problem : in every we have to look into previous row and replace 
               each occurence of 0 --> 01 and 1 --> 10

    return kth element in nth row;

    obeservation : 
    n=1     0
    n=2     0   1
    n=3     0   1   1   0
    n=4     0   1   1   0   1   0   0   1

    for n=1     Length = 1
        n=2     Length = 2
        n=3     Length = 4
        n=4     Length = 8
    length : 2^(n-1) = pow(2,n-1);

    for every k 
    if( k> midPointLength ){
        kth no of previous row element
    }
    else{
        !kth element from previous row element
    }     
*/

#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int kthGrammar(int n, int k)
{
    //Base case :
    if (n == 1 && k == 1)
    {
        return 0;
    }

    int mid = pow(2, n - 1) / 2;
    //Hypothesis :
    if (k <= mid)
    {
        return kthGrammar(n - 1, k);
    }
    else
    {
        return !kthGrammar(n - 1, k - mid);
    }
}

int main()
{
    int n;
    cout<<"Number of lines : ";
    cin>>n;

    int k;
    cout<<"Kth element in nth line of grammar : ";
    cin>>k;

    cout<<kthGrammar(n,k)<<endl;

    return 0;
}

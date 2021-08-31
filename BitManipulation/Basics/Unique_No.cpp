/*
    we have to find unique number among numbers :
    
    Approach : 
        - run two for loops and count the occurrences and print => O(n^2)
        - Store its frequency in array using counting sort and return freq==1 element =>TC:O(n) space : O(N)

        - Bitwise operator : XOR operator :
          a^b^a = b          

$ ./a.exe
5
3 1 4 3 1
unique no : 4

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n]={1,2,3,1,2};
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }

    cout<<"unique no : "<<ans;

    return 0;
}
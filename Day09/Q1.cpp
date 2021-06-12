//This question is very similar to max_area_histogram problem : 

//  2D-implementation of max_area_histogram problem : 

// Input:
// n = 4, m = 4
// M[][] = {{0 1 1 0},
//          {1 1 1 1},
//          {1 1 1 1},
//          {1 1 0 0}}
// Output: 8
// Explanation: For the above test case the
// matrix will look like
// 0 1 1 0
// 1 1 1 1
// 1 1 1 1
// 1 1 0 0
// the max size rectangle is 
// 1 1 1 1
// 1 1 1 1
// and area is 4 *2 = 8.


#include<iostream>
using namespace std;

int max_area_rectangle(int array[][100],int n,int m){
    
}

int main(){
    int n,m;
    cout<<"Size of array : ";
    cin>>n>>m;

    int array[100][100]={0};
    cout<<"Enter the array items : ";
    for(int idx=0;idx<n;idx++){
        for(int jdx=0;jdx<m;jdx++){
        cin>>array[idx][jdx];
        }
    }

    cout<<"Maximum area of histogram : "<<max_area_rectangle(array,n,m)<<endl;

    return 0;
}

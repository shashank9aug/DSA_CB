// Given a N x N matrix, where every row and column is sorted
// in non-decreasing order. Find the kth smallest element in the matrix.

// Input:
// N = 4
// mat[][] =     {{16, 28, 60, 64},
//                    {22, 41, 63, 91},
//                    {27, 50, 87, 93},
//                    {36, 78, 87, 94 }}
// K = 3
// Output: 27
// Explanation: 27 is the 3rd smallest element.

#include<iostream>
using namespace std;


int kth_smallest(int array[][100],int row,int col){
    
}


int main(){
    int row,col;
    cout<<"Enter the row and col : ";
    cin>>row>>col;

    int array[100][100];

    for(int idx=0;idx<row;idx++){
        for(int jdx=0;jdx<col;jdx++){
            cin>>array[idx][jdx];
        }
    }

    cout<<"Max value with specific pair : "<<kth_smallest(array,row,col)<<endl;

    return 0;
}
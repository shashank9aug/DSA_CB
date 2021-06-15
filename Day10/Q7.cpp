// Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.
// Example:

// Input :   0 1 1 0
//           1 1 1 1
//           1 1 1 1
//           1 1 0 0

// Output :  1 1 1 1
//           1 1 1 1

#include<iostream>
using namespace std;


int max_area(int mat[][100],int row,int col){
    
}


int main(){

    int row,col;
    cout<<"Enter the row and col : ";
    cin>>row>>col;

    int mat[100][100];

    for(int idx=0;idx<row;idx++){
        for(int jdx=0;jdx<col;jdx++){
            cin>>mat[idx][jdx];
        }
    }

    cout<<"Maximum area of "<<max_area(mat,row,col);


}
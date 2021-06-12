// Input:
// mat[M][N] = {{ 1, 2, -1, -4, -20 },
//              { -8, -3, 4, 2, 1 }, 
//              { 3, 8, 6, 1, 3 },
//              { -4, -1, 1, 7, -6 },
//              { 0, -4, 10, -5, 1 }};
// Output: 18
// The maximum value is 18 as mat[4][2] 
// - mat[1][0] = 18 has maximum difference
// Given an m x n matrix mat[m][n] of integers, find the maximum 
// value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d>b.


#include<iostream>
using namespace std;

int specific_pair(int array[][100],int row,int col){
    // c > a and d>b
    //max( ans , (mat(c, d) – mat(a, b)) )


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

    cout<<"Max value with specific pair : "<<specific_pair(array,row,col)<<endl;

    return 0;
}

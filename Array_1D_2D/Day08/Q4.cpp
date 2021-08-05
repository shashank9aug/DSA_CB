// Input: 
// N = 4 , M = 4
// Arr[][] = {{0, 1, 1, 1},
//            {0, 0, 1, 1},
//            {1, 1, 1, 1},
//            {0, 0, 0, 0}}
// Output: 2
// Explanation: Row 2 contains 4 1's (0-based
// indexing).


#include<iostream>
using namespace std;

//Brute force Approach : 
/*
int count_1s(int array[][100],int row,int col){
    int ans=INT32_MIN;
    for(int idx=0;idx<row;idx++){
        int count=0;
        for(int jdx=0;jdx<col;jdx++){
            if(array[idx][jdx]==1){
                count++;
            }
        }
        ans=max(count,ans);
    }
   return ans; 
}
*/

//Optimised approach using : Binary search 

int count_1s(int array[][100],int row,int col){
    
}



int main(){
    int row,col;
    cout<<"Enter the value of row and column : ";
    cin>>row>>col;

    int array[100][100]={0};
    cout<<"Enter the value of array elements : ";
    for(int idx=0;idx<row;idx++){
        for(int jdx=0;jdx<col;jdx++){
            cin>>array[idx][jdx];
        }
    }

    cout<<"cout max 1's in row : "<<count_1s(array,row,col)<<endl;

    return 0;
}
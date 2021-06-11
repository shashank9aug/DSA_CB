// Input:
// N=4
// Mat=[[10,20,30,40],
// [15,25,35,45] 
// [27,29,37,48] 
// [32,33,39,50]]
// Output:
// 10 15 20 25 
// 27 29 30 32
// 33 35 37 39
// 40 45 48 50
// Explanation:
// Sorting the matrix gives this result.

#include<iostream>
using namespace std;

void sort_matrix(int array[][100],int row,int col){
        
}


int main(){
    int row,col;
    cout<<"Enter the value of row and column : ";
    cin>>row>>col;

    int array[100][100]={0};
    cout<<"Enter the value of inside 2d array : ";

    int val=1;
    for(int idx=0;idx<row;idx++){
        for(int jdx=0;jdx<col;jdx++){
           array[idx][jdx]=val;
           val++;
        }
    }

    sort_matrix(array,row,col);

    cout<<"sorted array is : ";
    for(int idx=0;idx<row;idx++){
        for(int jdx=0;jdx<col;jdx++){
            cout<<array[idx][jdx]<<",";
        }
    }

    return 0;
}
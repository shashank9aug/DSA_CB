// Rotate a matrix by 90 degree in clockwise direction without using any extra space

// Input:
// 1 2 3 
// 4 5 6
// 7 8 9  
// Output:
// 7 4 1 
// 8 5 2
// 9 6 3


#include<iostream>
using namespace std;

//Brute force
void rotate_90degree(int array[][100],int row,int col){

    for(int idx=0;idx<row;idx++){
        for(int jdx=0;jdx<col;jdx++){
            //swap the elements in clock wise manner

            



        }
    }
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

    rotate_90degree(array,row,col);

    cout<<"Matrix after rotation : ";
    for(int idx=0;idx<row;idx++){
        for(int jdx=0;jdx<col;jdx++){
            cout<<array[idx][jdx]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
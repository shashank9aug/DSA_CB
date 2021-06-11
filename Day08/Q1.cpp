// r = 4, c = 4
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12},
//            {13, 14, 15,16}}
// Output: 
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10


#include<iostream>
using namespace std;

//Passing 2d array as argument and inside funtion is important.

void spiral_print(int array[][100],int row,int col){
    //4 pointer's for the traversal
    int sr=0,er=(row-1),sc=0,ec=(col-1);
    int dir=0;
    //print the 2d array :
    while(sr<=er and sc<=ec){
        //top row
       if(dir==0){ 
            for(int idx=sc;idx<=ec;idx++){
                cout<<array[sr][idx]<<",";
            }
            sr++;
        } 
        else if(dir==1){
            for(int jdx=sr;jdx<=er;jdx++){
                cout<<array[jdx][ec]<<",";
            }
            ec--;
        }
        //botom-up 
        else if(dir==2){
            for(int idx=ec;idx>=sc;idx--){
                cout<<array[er][idx]<<",";
            }
            er--;
        }    
        else if(dir==3){
            for(int idx=er;idx>=sr;idx--){
                cout<<array[idx][sc]<<",";
            }
            sc++;
        }
       dir=(dir+1)%4; 
    }

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

    spiral_print(array,row,col);

    cout<<"array is : ";
    for(int idx=0;idx<row;idx++){
        for(int jdx=0;jdx<col;jdx++){
            cout<<array[idx][jdx]<<",";
        }
    }

    return 0;
}
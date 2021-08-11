/*
    Given NxN matrix in which N subgrids will be present :
    we have to fill the each grid : 
    rules  :
    - number should not match with each other in row and column 
    - grid size should be sqrt(n)*sqrt(n) for each grid.
    - print the grid when it will hit the base case. 

*/


#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool canPlace(int mat[][9],int i,int j,int n,int number){
    //in row and col check: 
    for(int x=0;x<n;x++){
        if(mat[x][j]==number or mat[i][x]==number){
            return false;
        }
    }

    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;

    for(int x=sx;x<sx+rn;x++){
        for(int y=sy;y<sy+rn;y++){
            if(mat[x][y]==number){
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int mat[][9],int i,int j,int n){
    //Base case : 
    if(i==n){
        //print the solution :
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                cout<<mat[a][b]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //case row end : 
    if(j==n){
        return solveSudoku(mat,i+1,0,n);            
    }
    //skip the pre filled cells : 
    if(mat[i][j]!=0){
        return solveSudoku(mat,i,j+1,n);
    }
    //Rec case : 
    //fill the current position with possible numbers :
    for(int number=1;number<=n;number++){
        if(canPlace(mat,i,j,n,number)){
            //Assume : 
            mat[i][j]=number;

            bool couldWeSolve=solveSudoku(mat,i,j+1,n);
            if(couldWeSolve==true){
                return true;
            }        
        }
    }
    //Back track : we have tryied to add and check for 1 to n at mat[i][j] but if it will not return true then back track 
    mat[i][j]=0; 

    return false;
}


int main(){
    int mat[9][9]=
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,2},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    solveSudoku(mat,0,0,9);

    return 0;
}
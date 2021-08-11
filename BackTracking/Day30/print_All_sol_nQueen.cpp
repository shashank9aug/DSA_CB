/*
    we have NxN matrix and N number of queens:
    we have to place all the queens in board such that no queens can kill each other.

    i.e : their should not be any queen in row or column and on diagonal of matrix.

4
_ Q _ _ 
_ _ _ Q
Q _ _ _
_ _ Q _

_ _ Q _
Q _ _ _
_ _ _ Q 
_ Q _ _


*/

#include<iostream>
using namespace std;

bool canPlace(char board[][100],int row,int col,int n){

    ///Row mein queen to nahi h
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }
    ///Col mein queen to nahi h
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    /// Diagonals
    ///Top Left
    int i=row,j=col;
    while(i>=0&&j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }
    ///Top Right
    i=row,j=col;
    while(i>=0 && j<n){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j++;
    }

    return true;
}



bool solveNQueen(char board[][100],int n,int row){
    if(row==n){
        ///Print the board
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                cout<<board[x][y]<<" ";
            }
            cout<<endl;

        }
        cout<<endl;
        // return true;

        //false will help us to search for the next valid configuration
        return false;
    }

    ///Rec Case

    ///Try to place the queen in the current row

    for(int pos=0;pos<n;pos++){

            if(canPlace(board,row,pos,n)){
                    board[row][pos]='Q';

                    //recurssive step :     
                    bool agliQueenRakhPayeKya = solveNQueen(board,n,row+1);
                    if(agliQueenRakhPayeKya==true){
                        return true;
                    }
                    //Backtrack step : 
                    board[row][pos]='_';
            }

    }
    return false;
}

int main(){

    char board[100][100];

    int n;
    cin>>n;

    for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                board[x][y]='_';
            }

        }
    solveNQueen(board,n,0);


return 0;
}
// R = 3, C = 3
// M = [[1, 3, 5], 
//      [2, 6, 9], 
//      [3, 6, 9]]

// Output: 5

// Explanation:
// Sorting matrix elements gives us 
// {1,2,3,3,5,6,6,9,9}. Hence, 5 is median.


#include<iostream>
#include<algorithm>
using namespace std;

//Brute force with extra space :
int array_median(int array[][100],int row,int col){
    // code here      
    int size = row*col;
    int s=0;
    int ans[size];
    for(int idx=0;idx<row;idx++){
        for(int jdx=0;jdx<col;jdx++){
            ans[s++]=array[idx][jdx];
        }    
    }
    sort(ans,ans+size);
    if(size%2 == 0){
        return (ans[size/2]+ans[size/2 - 1])/2;
    }    
    else{
        return (ans[size/2]);
    }    
}

//Optimised approach can be about implementing Binary search 

int main(){
    int row,col;
    cout<<"Enter the value of row and col : ";
    cin>>row>>col;

    int array[100][100]={0};

    int val=1;
    for(int idx=0;idx<row;idx++){
        for(int jdx=0;jdx<col;jdx++){
            array[idx][jdx]=val;
            val++;    
        }
    }

    cout<<"Median inside 2d array : "<<array_median(array,row,col)<<endl;

    return 0;
}
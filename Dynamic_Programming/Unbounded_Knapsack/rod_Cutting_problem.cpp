/*
Rod Cutting Problem
 Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the  maximum value obtainable by cutting up the rod and selling the pieces. 
Example: 
if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)


length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

*/

#include<iostream>
#include<vector>
using namespace std;

int max_profit(int len,vector<int>length,vector<int>price){
    vector<vector<int>>v(len,vector<int>(len,0));

    

}

int main(){
    int len;
    cin>>len;

    vector<int>length;
    vector<int>price;

    for(int i=len;i>=1;i--){
        length.push_back(i);
    }

    for(int i=0;i<len;i++){
        int d;
        cin>>d;
        price.push_back(d);
    }

    cout<<"Maximum profit : "<<max_profit(len,length,price)<<endl;

    return 0; 
}
//We have to maximise the profit by buying and selling twice :

// Input:   price[] = {10, 22, 5, 75, 65, 80}
// Output:  87
// Trader earns 87 as sum of 12, 75 
// Buy at 10, sell at 22, 
// Buy at 5 and sell at 80

// Input:   price[] = {2, 30, 15, 10, 8, 25, 80}
// Output:  100
// Trader earns 100 as sum of 28 and 72
// Buy at price 2, sell at 30, buy at 8 and sell at 80

#include<iostream>
using namespace std;

//Brute force : TC O(N^2)
int max_profit(int array[],int size){
    int profit=0;
    int max_profit=0;
    for(int idx=0;idx<size;idx++){
        for (int jdx = idx+1; jdx < size; jdx++)
        {

        }
        
    }
}

int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    cout<<"Maximum profit that can we get : "<<max_profit(array,size)<<endl;

    return 0;
}
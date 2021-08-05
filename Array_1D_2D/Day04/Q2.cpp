// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


#include<iostream>
#include<climits>
using namespace std;

//Brute force approach

int best_time_buyStock(int array[],int size){
    int max_profit=0;
    for(int idx=0;idx<size;idx++){
        int max_value=array[idx];
        for(int jdx=idx+1;jdx<size;jdx++){
            if(array[jdx]>array[idx]){
                max_profit=max(max_profit,array[jdx]-array[idx]);
            }
        }
    }
    return max_profit;
} 



//O(n)
// int best_time_buyStock(int array[],int size){
//     int max_profit=0;
//     int min_price=INT_MAX;
//     for(int idx=0;idx<size;idx++){
//         min_price=min(min_price,array[idx]);
//         max_profit=max(max_profit,array[idx]-min_price);
//     }
//     return max_profit;
// }

int main(){
    int size;
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    cout<<best_time_buyStock(array,size)<<endl;

    return 0;
    
}
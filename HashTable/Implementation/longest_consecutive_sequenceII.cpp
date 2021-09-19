/*
    storing each element of array inside set then we are just checking for next element of each arr[i]

    if(arr[i]-1 ) => not present inside set then we just iterating over the set element untill streak break
*/


#include<iostream>
#include<unordered_set>
using namespace std;


int longestConsecutive(int arr[],int n){
    unordered_set<int>us; //store each element of array 

    for(int i=0;i<n;i++){
        us.insert(arr[i]);  //O(1) time
    }

    //iterate over all the element 
    //target those from which streak can be start.
    int maxStreak=0;
    for(int i=0;i<n;i++){
        if(us.find(arr[i]-1)==us.end()){
            //arr[i] as starting point of streak
            //traverse the entire range that contained in that streak
            int nextNo=arr[i]+1;
            int streakLen=1;
            while(us.find(nextNo)!=us.end()){
                nextNo+=1;
                streakLen+=1;
            }
            maxStreak=max(streakLen,maxStreak);
        }
    }
    return maxStreak;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<longestConsecutive(arr,n)<<endl;

    return 0;
}
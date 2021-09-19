/*
    We have to find the longest consecutive sequence inside array .

    - using hash map (unordered_map) storing streak length and return maximum streak length


PS D:\GitHub\Algo++\HashTable\Implementation> ./a.exe
9
14 5 1 2 6 7 8 9 4
Longest consecutive sequence : 6


Longest consecutive sequence : 4 5 6 7 8 9  =>  6 


PS D:\GitHub\Algo++\HashTable\Implementation> ./a.exe
10
14 5 1 2 6 7 8 9 4 3
Longest consecutive sequence : 9

We join two streak by inserting 3 in array.
Longest consecutive sequence : 1 2 3 4 5 6 7 8 9  =>  9 

----------------------------------------------------------------------------------

getting error :
4
[1,2,0,1]
-> 3 (expected)
-> 7 (getting)
*/


#include<iostream>
#include<unordered_map>
using namespace std;


int longestConsSeq(int arr[],int n){
    
    unordered_map<int,int>ump;   // <number , streak_length>

    //insert every element in hashmap and correspondingly update its streak length
    for(int i=0;i<n;i++){
        int no=arr[i];

        //check for existence of no-1 and no+1 of every no and grow and shrink the streak length accordingly
        //Both the number not present.
        if(ump.count(no-1)==0 and ump.count(no+1)==0){
            ump[no]=1;
        }
        else if(ump.count(no-1) and ump.count(no+1)){
            //left streak length
            int len1=ump[no-1];
            //right streak length
            int len2=ump[no+1];

            //total streak lenght => +1 due to no is inserting inside streak
            int streak=len1+1+len2;
            //starting point of streak update
            ump[no-len1]=streak;
            //ending point of streak update
            ump[no+len2]=streak;
        }
        //left part present only
        else if(ump.count(no-1) and !ump.count(no+1)){
            int len=ump[no-1];  //1,2,3   7,8,9  [4] => 3,5  (3->present only)
            ump[no-len]=len+1;
            ump[no]=len+1;
        }
        else{
            int len=ump[no+1];  //5,6,7  9(4),10,11,12(4).  [9]
            ump[no+len]=len+1;
            ump[no]=len+1;
        }
    }

    int maxVal=0;

    for(auto u:ump){
        maxVal=max(maxVal,u.second);
    }

    return maxVal;
}



int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Longest consecutive sequence : "<<longestConsSeq(arr,n)<<endl;

    return 0;
}
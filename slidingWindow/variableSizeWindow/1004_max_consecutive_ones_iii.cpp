#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
$ ./a.exe
11
1 1 1 0 0 0 1 1 1 1 0
2
1, 
Current Window : 1
1, 1,
Current Window : 2
1, 1, 1,
Current Window : 3
1, 1, 1, 0,
Current Window : 4
1, 1, 1, 0, 0, 
Current Window : 5
0, 0,
Current Window : 2
0, 0, 1,
Current Window : 3
0, 0, 1, 1,
Current Window : 4
0, 0, 1, 1, 1,
Current Window : 5
0, 0, 1, 1, 1, 1,
Current Window : 6
0, 1, 1, 1, 1, 0,
Current Window : 6
6

*/


int longestOnes(vector<int>& nums, int k) {
    int i=0;
    int j=0;
    int mx_window=INT_MIN;
    int count_0=0;
    while(j<nums.size()){
            
        if(nums[j]==0){
            count_0++;
        }
        while(count_0>k){
            if(nums[i]==0){
                count_0--;
            }
            i++;
        }     
        //ans from calculation :
        mx_window=max(mx_window,(j-i+1));
        for(int a=i;a<=j;a++){
            cout<<nums[a]<<", ";
        }
        cout<<endl;
        cout<<"Current Window : "<<(j-i+1)<<endl;                
        //slide the pointer   
        j++; 
    }
    return mx_window;
}

int main(){
    int n;
    cin>>n;

    vector<int>v;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        v.push_back(d);
    }

    int k;
    cin>>k;

    cout<<longestOnes(v,k);

    return 0;

}
#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> firstNegative(int arr[],int N,int K){
    int i=0,j=0;
    vector<int>ans;
    deque<int>list;
    while(j<N){
        if( arr[j]<0){
            list.push_back(arr[j]);
        }
            
        if(j-i+1<K){
           j++;
           continue;
        }
            
        else if(j-i+1==K){
            if(!list.empty()){
               ans.push_back(list.front());             
            }
            else{
                ans.push_back(0);
            }

            if(arr[i]<0){
                list.pop_front();
            }
            i++;
        }
        j++;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   

    int k;
    cout<<"Enter window size : ";
    cin>>k;

    vector<int>ans=firstNegative(arr,n,k);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<", ";
    }

    return 0;
}
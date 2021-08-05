
// given value of K we have to find triplet of sum equal to k

#include<iostream>
#include<vector>
using namespace std;




vector<int> check_triplet(int array[],int size,int k){
    int curr=0;
    
    vector<int>ans;
    while(curr<(size-2)){
       int next=curr+1;
       int far=next+2;  
       for(int idx=far;idx<size;idx++){
         if((array[curr]+array[next]+array[far])==k){
            ans.push_back(array[curr]);
            ans.push_back(array[next]);
            ans.push_back(array[far]);
          }
        } 
      curr++;

    }
   return ans; 
}

//Brute force approach : O(n^3)
// bool check_triplet(int array[],int size,int k){
//     bool ans=false;    
//     for(int idx=0;idx<size;idx++){
//         for(int jdx=idx;jdx<size;jdx++){
//             for(int kdx=idx+1;kdx<size;kdx++){
//                 if(array[idx]+array[jdx]+array[kdx]==k){
//                     ans=true;
//                 }
//             }
//         }
//     }
//     return ans;
// }




int main(){
    int size;
    cout<<"Enter the size of Array : ";
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    int k;
    cout<<"Enter the value of k :";
    cin>>k;

    vector<int>ans=check_triplet(array,size,k);
    
    // cout<<"Triplet present or not :"<<check_triplet(array,size,k);
    for(int idx=0;idx<ans.size();idx++){
        cout<<ans[idx]<<" ";
    }
    
    return 0;
}
//Find missing and repeating element inside array

// Input:
// N = 2
// Arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and 
// smallest positive missing number is 1.


#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans=new int(2);
        // int count=0;
        
        // //duplicate element :
        // int occ=arr[0];
        // for(int i=1;i<n;i++){
        //     if(occ==arr[i]){
        //         ans[0]=arr[i];
        //     }
        //     else{
        //         occ=arr[i];
        //     }
        // }
        
        
        // //find missing item in sequence : 
        // for(int i=0;i<n;i++){
        //     //record the counting 1,2,3....N
        //     if(arr[i]!=i+1){
        //         ans[1]=(i+1);
        //     }
        // }
        int count[n+1]={0};
        int rep=0;
        int miss=0;
        for(int i=0;i<n;i++){
            count[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(count[arr[i]]>1){
                ans[0]=i;
            }
            if(count[arr[i]]==0){
                ans[1]=i;
            }
        }
        if(ans[1]==0){
            ans[1]=n;
        }
        return ans;        
    }
};


int main() {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}  
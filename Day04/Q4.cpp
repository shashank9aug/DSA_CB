// Input:
// n1 = 6; A = {1, 5, 10, 20, 40, 80}
// n2 = 5; B = {6, 7, 20, 80, 100}
// n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
// Output: 20 80
// Explanation: 20 and 80 are the only
// common elements in A, B and C.
// all array's are sorted


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> common_elements(int array1[],int array2[],int array3[],int size1,int size2,int size3){
    int idx=0,jdx=0,kdx=0;
    vector<int>common;
    while(idx<size1 && jdx<size2 && kdx<size3){
        if(array1[idx]==array2[jdx] && array2[jdx]==array3[kdx]){
            if(find(common.begin(),common.end(),array1[idx])==common.end()){
                common.push_back(array1[idx]);
                idx++;jdx++;kdx++;
            }
        }
        else if(array1[idx]<array2[jdx]){ idx++; }
        else if(array1[idx]>array2[jdx]){ jdx++; }
        else  kdx++;

    }
    return common;

}

int main(){
    int size1,size2,size3;
    cin>>size1>>size2>>size3;

    int array1[size1],array2[size2],array3[size3];

    for(int idx=0;idx<size1;idx++){
        cin>>array1[idx];
    }

    for(int idx=0;idx<size2;idx++){
        cin>>array2[idx];
    }

    for(int idx=0;idx<size3;idx++){
        cin>>array3[idx];
    }


    vector <int> res = common_elements(array1,array2,array3,size1,size2,size3);
        if (res.size () == 0) 
            cout << -1;
        cout<<"Common Elements are : "<<" ";    
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;    

    return 0;
}
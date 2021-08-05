// Input:
// a1[] = {11, 1, 13, 21, 3, 7}
// a2[] = {11, 3, 7, 1}
// Output:
// Yes
// Explanation:
// a2[] is a subset of a1[]

#include<iostream>
using namespace std;

//Brute force
bool check_subset(int array1[],int array2[],int size1,int size2){
    bool flag=false;
    for(int idx=0;idx<size2;idx++){
        for(int jdx=0;jdx<size1;jdx++){
            if(array2[idx]==array1[jdx]){
                flag=true;
            }
        }
    }
    return flag;
}

//it can be Optimise using c++ stl :



int main(){
    int size1,size2;
    cout<<"Enter the size of array : ";
    cin>>size1>>size2;

    int array1[size1],array2[size2];
    cout<<"Enter elements of array1 :";
    for(int idx=0;idx<size1;idx++){
        cin>>array1[idx];
    }

    cout<<"Enter elements of array2 :";

    for(int idx=0;idx<size2;idx++){
        cin>>array2[idx];
    }

    cout<<"array-2 subaset of array-1 : "<<check_subset(array1,array2,size1,size2)<<endl;

    return 0;
}
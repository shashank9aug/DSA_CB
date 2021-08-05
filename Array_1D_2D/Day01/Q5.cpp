#include<iostream>
#include<algorithm>
using namespace std;

//Brute force
void negative_asside(int array[],int size){
    int start=0;

    for(int idx=0;idx<size;idx++){
        if(array[idx]<0){
            if(idx!=start){
                swap(array[start],array[idx]);
            }
            start++;
        }
    }
}

// bool compare(int a,int b){
//     return a<b ? true : false ;
// }


//another method using sorting
int main(){
    int size;
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }
    negative_asside(array,size);

    //negative elements on left side
    // sort(array,array+size);

    //negative elements on right side
    // sort(array,array+size,compare);
    for (int idx = 0; idx < size; idx++)
    {
        cout<<array[idx]<<",";
    }
    return 0; 
}
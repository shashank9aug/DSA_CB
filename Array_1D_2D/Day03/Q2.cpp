#include<iostream>
using namespace std;

void merge_two_array(int array1[],int array2[],int size1,int size2){
    
}


int main(){
    int size1,size2;
    cin>>size1>>size2;

    int array1[size1],array2[size2];

    for(int idx=0;idx<size1;idx++){
        cin>>array1[idx];
    }
    for(int idx=0;idx<size2;idx++){
        cin>>array2[idx];
    }

    merge_two_array(array1,array2,size1,size2);

    return 0;

}
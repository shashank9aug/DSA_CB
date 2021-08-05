#include<iostream>
#include<climits>
using namespace std;

int max_element(int array[],int size){
    int max_num=INT_MIN;
    for(int idx=0;idx<size;idx++){
        if(array[idx]>max_num){
            max_num=array[idx];
        }
    }
    return max_num;
}

int min_element(int array[],int size){
    int min_num=INT_MAX;
    for(int idx=0;idx<size;idx++){
        if(array[idx]<min_num){
            min_num=array[idx];
        }
    }
    return min_num;
}



int main(){
    int size;
    cout<<"Enter the size of Array: ";
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    cout<<"Maximum element inside array: "<<max_element(array,size)<<endl;;

    cout<<"Minimum element inside array: "<<min_element(array,size)<<endl;
    
    return 0;
}
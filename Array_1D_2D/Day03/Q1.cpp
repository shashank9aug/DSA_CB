//find Duplicates in array : 

#include<iostream>
using namespace std;

//Brute force
bool find_duplicates(int array[],int size){
    for(int idx=0;idx<size;idx++){
        int last_element=array[idx];
        for(int idx_next=(idx+1);idx_next<size;idx++){
            if(array[idx_next]==last_element){
                return true;
            }
        }
    }
    return false;
}

//we can use stl containers to optimize time complexity

int main(){
    int size;
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    
    cout<<"Duplicates in array of size N+1 : "<<find_duplicates(array,size)<<endl;

    return 0;
}

//It had attempted this question only due to vaccination : sad

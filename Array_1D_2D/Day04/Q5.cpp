
// Input:  arr[] = {1, 2, 3, -4, -1, 4}
// Output: arr[] = {-4, 1, -1, 2, 3, 4}

#include<iostream>
using namespace std;

void arrange_elements(int array[],int size){
    int left=0,right=size-1;
    while(right>=left){
        if(array[left]>0 && array[right]<0){
            left++;
            right--;
        }
        else if(array[left]<0 && array[right]>0){
            swap(array[left],array[right]);
            left++;
            right--;
        }
        else if(array[left]<0 && array[right]<0) {
            right--;
        }
        else if(array[left]>0 && array[right]>0){
            left++;
        }
    }
    //left will point to the starting of -ve element inside array
    // cout<<"Left position : "<<left<<endl;
    

    //either all positive or all negative element 
    if(left==0 or left==size){
        for(int m=0;m<size;m++){
            cout<<array[m];
        }
    }
    //some positive element and -ve element
    else{
        int k=0;
        while(k<size and left<size){
            swap(array[k],array[left]);
            k+=2;
            left++;
        }
    }    
}


int main(){
    int size;
    cin>>size;

    int array[size];

    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    arrange_elements(array,size);

    for(int idx=0;idx<size;idx++){
        cout<<array[idx]<<" ";
    }
    return 0;
}
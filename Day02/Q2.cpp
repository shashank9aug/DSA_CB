//cyclically rotate array by one
#include<iostream>
#include<algorithm>
using namespace std;

// void cyclically_rotate(int array[],int size){
   
// }

int main(){
    int size;
    cin>>size;

    int array[size];
    for(int idx=0;idx<size;idx++){
        // cin>>array[size];
        
        //I have taken input at the cyclically rotaed position
        cin>>array[(size+idx-(size-1))%size];
    }

    // cyclically_rotate(array,size);

    // int end=size-1;
    // int start=0;
    // while(start<end){
    //     swap(array[start],array[end]);
    //     start++;
    //     end--;
    // }
       
    cout<<"cyclically rotated array: ";
    for(int idx=0;idx<size;idx++){
        cout<<array[idx]<<","; 
    }
 
}
// Input: N = 5
// arr[] = 90 100 78 89 67
// Output: 89
// Explanation: After sorting the array 
// middle element is the median 

#include<iostream>
#include<algorithm>
using namespace std;

int median_element(int array[],int size){
    //sort the array and get the median as middle element
    //but size of array can be odd or even

    if( (size%2) != 0 ){
        return array[size/2];
    }
    return (array[(size-1)/2]+array[size/2])/2;
}


int main(){

    int size;
    cout<<"Enter the size of array : ";
    cin>>size;

    int array[size];
    cout<<"Enter the array elements : ";

    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    sort(array,array+size);


    cout<<"Median of array : "<<median_element(array,size);

    return 0;

}
// Input: ar1[] = {-5, 3, 6, 12, 15}
//         ar2[] = {-12, -10, -6, -3, 4, 10}
// Output : The median is 3.
// Explanation : The merged array is :
//         ar3[] = {-12, -10, -6, -5 , -3,
//                  3, 4, 6, 10, 12, 15},
//        So the median of the merged array is 3


#include<iostream>
#include<algorithm>
using namespace std;

//Brute force : 
int median_element(int array1[],int array2[],int size1,int size2){
    int size3=size1+size2;
    int array3[size3];

    for(int idx=0;idx<size1;idx++){
        array3[idx]=array1[idx];
    }

    for(int idx=0;idx<size2;idx++){
        array3[idx+size1]=array2[idx];
    }

    sort(array3,array3 + size3);

    if( (size3 %2) != 0 ){
        return array3[size3 /2];
    }
    return (array3[(size3 -1)/2]+array3[size3/2])/2; 
}

int main(){
    int size1,size2;
    cout<<"size1 of array1 : ";
    cin>>size1;
    cout<<"size2 of array2 : ";
    cin>>size2;

    int array1[size1],array2[size2];
    cout<<"Enter the array1 items : ";

    for(int idx=0;idx<size1;idx++){
        cin>>array1[idx];
    }

    cout<<"Enter the array2 items : ";

    for(int idx=0;idx<size2;idx++){
        cin>>array2[idx];
    }

    //sort the array by stl so TC : O(NlogN)
    sort(array1,array1+size1);
    sort(array2,array2+size2);
    cout<<"median of two sorted array : "<<median_element(array1,array2,size1,size2);

    return 0;
}
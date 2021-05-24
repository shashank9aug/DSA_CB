// Union : selecting common elements from array and then selecting uncommon element and add in array

// Intersection :selecting only common elements in two array

#include<iostream>
using namespace std;

void union_array(int array1[],int array2[],int size1,int size2){
    int *array_3=new int[size1+size2]{0};

    int j=0;
    for(int idx=0;idx<size1;idx++){
        while(j<size2){
            if(array1[idx]<array2[j]){
                array_3[idx]=array1[idx];
            }
            else if(array1[idx]>array2[j]){
                array_3[idx]=array2[j];
                j++;
                array_3[idx]=array1[idx];
            }
            else{
                array_3[idx]=array1[idx];
                j++;
            }
        }
    }

    
}

void intersection_array(int array1[],int array2[],int size1,int size2){
    int array_3[size1+size2]={0};
    for(int idx=0;idx<size1;idx++){
        for(int idx1=0;idx1<size2;idx1++){
            if(array1[idx]==array2[idx1]){
                array_3[idx]=array1[idx1];
            }            
        }
    }

    for(int idx=1;idx<(size1+size2);idx++){
        cout<<array_3[idx]<<",";
    }
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
    
    // union_array(array1,array2,size1,size2);

    intersection_array(array1,array2,size1,size2);

    return 0;
}
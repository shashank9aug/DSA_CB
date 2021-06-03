
//Traiping rain water problem  : prefix sum 

// N = 6
// arr[] = {3,0,0,2,0,4}
// Output:
// 10

#include<iostream>
using namespace std;

int traiping_rainwater(int array[],int size){
    int max_till[size];
    max_till[0]=array[0];
    for(int idx=1;idx<size;idx++){
        max_till[idx]=max(max_till[idx-1],array[idx]);
    }
    int rain_water=0;
    for(int idx=0;idx<size;idx++){
        rain_water+=(max_till[idx]-array[idx]);
    }
    return rain_water;
}

int main(){
    int size;
    cin>>size;

    int array[size];

    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    cout<<"Rain water trapped inside Building's : "<<traiping_rainwater(array,size)<<endl;    

    return 0;
}
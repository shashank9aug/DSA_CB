#include<iostream>
using namespace std;

//We are counting the no of 0,1,2 inside array and then printing that many no of 0,1,2

void sort_012(int array[],int size){
    int c[3]={0};
    for(int idx=0;idx<size;idx++){
        if(array[idx]==0){
            c[0]++;
        }else if(array[idx]==1){
            c[1]++;
        }
        else{
            c[2]++;
        }
    }
    
    int idx=0;
    for(int i=0;i<3;i++){
        while(c[i]!=0){
            array[idx]=i;
            idx++;
            c[i]=c[i]-1;
        }
    }    
}

int main(){
    int idx;
    int size;
    cin>>size;

    int array[size];
    for(idx=0;idx<size;idx++){
        cin>>array[idx];
    }
    
    sort_012(array,size);

    for(idx=0;idx<size;idx++){
        cout<<array[idx]<<",";
    }

    return 0;

}
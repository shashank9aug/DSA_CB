#include<iostream>
using namespace std;

//Brute force method
void array_reverse(int array[], int s){
    int i=0,j=s-1;
	while(i<=j){
		swap(array[i],array[j]);
        i++;
        j--;
	}
}

//logical method : while taking input we can add number into it's reversed position

int main(){
	int size;
    cin>>size;
	int array[size];

	//if size will not given :
	// size=sizeof(array)/sizeof(array[0]);
	
	for(int idx=0;idx<size;idx++){
		cin>>array[idx];

		// rotate the array from given positon
		// cin>>array[(idx+size-position)%size];
	}

	array_reverse(array,size);

	for(int idx=0;idx<size;idx++){
		cout<<array[idx]<<",";
	}
	return 0;	
}
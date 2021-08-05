


#include<iostream>
#include<algorithm>
using namespace std;


//Brute force : O(nlogn) + O(n) = O(nlogn)

/* what we can do :
   a)   1: we traverse the entire array and store it's element occurences 
        2: linear search to find occurence which is greater than n/k times 
   
   b)   1: sort the array with O(NlogN) complexity
        2: apply linear search to find the occurence greater than n/k        
*/
int find_occurences(int array[],int size,int k){

    int occurrence=(size/k);
    int count=0;
    sort(array,array+size);
    int occ_count=1;
    for(int idx=0;idx<size;idx++){
        if(array[idx]==array[idx+1]){
            occ_count++;
        }
        else{
            occ_count=1;
        }
        if(occ_count>occurrence){
            
        }
    }
}

int main(){
    int size;
    cout<<"size of the array : ";
    cin>>size;

    int array[size];
    cout<<"Elements of array : ";
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    int k;
    cout<<"Value of K :";
    cin>>k;

    cout<<"occurences of element : "<<find_occurences(array,size,k)<<endl;

    return 0;

}
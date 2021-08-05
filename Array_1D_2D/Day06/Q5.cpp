// N = 8, M = 5
// A = {3, 4, 1, 9, 56, 7, 9, 12}
// Output: 6
// Explanation: The minimum difference between 
// maximum chocolates and minimum chocolates 
// is 9 - 3 = 6 by choosing following M packets :
// {3, 4, 9, 7, 9}.

// we have to minimize the difference between max choclate distributed and min choclate distributed in m students

#include<iostream>
#include<algorithm>
using namespace std;

int min_choclate_distributed(int array[],int size,int student){
    int min_diff=INT32_MAX;
    int diff;
    for(int idx=0;(idx+student-1)<size;idx++){
        int jdx=(idx+student-1);
        diff=array[jdx]-array[idx];
        min_diff=min(min_diff,diff);
    }
    return min_diff;
}

int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;

    int student;
    cout<<"Enter the number of students : ";
    cin>>student;

    int array[size];
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }
    sort(array,array+size);
    for(int idx=0;idx<size;idx++){
        cout<<array[idx];
    }
    cout<<"Minimum no of choclate distributed : "<<min_choclate_distributed(array,size,student)<<endl;

    return 0;

}
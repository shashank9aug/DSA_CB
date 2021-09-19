/*
    Given n points in 2D cartesian plane 
    How many triangles are their such that perpendicular or base is parallel to x or y axis..?


    Count of right-angled triangles = (frequencies of X coordinates – 1) * (frequencies of Y coordinates – 1)


    - Approach : 
    i):count the no of points lies on same axis taking (x,y) as pivot.
    ii): no of possible traingles taking (x,y) as pivot => (n-1)C(1) * (n-2)C(1) = (n-1)*(n-2)

PS D:\GitHub\Algo++\HashTable\Implementation> ./a.exe
5
1 2
2 1
2 2
2 3
3 2
Possible right angled traingle : 4


*/

#include<iostream>
#include<unordered_map>
using namespace std;

int countRightTraingle(int arr[][2],int n){
    //store cordinates having same x cordinates
    unordered_map<int,int>umpx;
    //store cordinates having same y cordinates
    unordered_map<int,int>umpy;

    for(int i=0;i<n;i++){
        umpx[arr[i][0]]++;
        umpy[arr[i][1]]++;
    }

    int count=0;

    //count total number of possible traingle.
    for(int i=0;i<n;i++){
        if(umpx[arr[i][0]]>=1 and umpy[arr[i][1]]>=1){
            //count of no of points have same x-ordinates and same y-ordinates
            // Count of right-angled triangles = (frequencies of X coordinates – 1) * (frequencies of Y coordinates – 1)
            count+=(umpx[arr[i][0]]-1)*(umpy[arr[i][1]]-1);
        }
    }
    return count;
}


int main(){
    int n;
    cin>>n;

    int arr[100][2];

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Possible right angled traingle : "<<countRightTraingle(arr,n)<<endl;

    return 0;
}
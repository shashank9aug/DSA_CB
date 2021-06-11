// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true


#include<iostream>
using namespace std;

//Brute force : linear search
// int search_matrix(int array[][100],int row,int col,int key){
//     int flag=0; 

//     for(int idx=0;idx<row;idx++){
//         for(int jdx=0;jdx<col;jdx++){
//             if(array[idx][jdx]==key){
//                 flag=1;
//                 return flag;
//             }
//         }
//     }    
//     return flag;
// }


//Optimise approach : stair case search : 2d matrix should be sorted :rowise/column wise 
// int stair_search(int array[][100],int n,int m,int key){
// 	int end=m-1;
// 	int start=0;
// 	int flag=0;
//     while(start>=0 && start<n && end>=0 && end<=m){
// 		if(array[start][end]==key){
//             flag=1;
//             return flag;
// 			break;
// 		}
// 		else if(array[start][end] < key){
// 			start++;
// 		}
// 		else{
// 			end--;
// 		}
// 	}
//     return flag;
// }

//We can apply binay search on matrix as well:

//O(NLogN) : optimised 
//apply binary search on every row :

int binary_search(int array[][100],int row,int col,int key){
    int flag=0;
    int start=0;
    int end=col-1;
    for(int idx=0;idx<row;idx++){
         int l = 0, r = col-1, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
 
            if (array[idx][mid] == key)
            {
                flag=1;
                return flag;
                break;
            }
 
            if (array[idx][mid] > key)
                r = mid - 1;
            if (array[idx][mid] < key)
                l = mid + 1;
        }
    } 
    return flag;
}



int main(){
    int n,m;
    cout<<"Enter the value of row and column : ";
    cin>>n>>m;

    int array[100][100]={0};

    int val=1;
    for(int idx=0;idx<n;idx++){
        for(int jdx=0;jdx<m;jdx++){
           array[idx][jdx]=val;
           val++;
        }
    }

    int key;
    cout<<"Enter the value need to search : ";
    cin>>key;

    cout<<"Search in matrix : ";
    // int ans=linear_search(array,n,key);
    // int ans=stair_search(array,n,m,key);

    int ans = binary_search(array,n,m,key);

    if(ans){
        cout<<"Key exist";
    }
    else{
        cout<<"key not exist";
    }
   
    return 0;
}
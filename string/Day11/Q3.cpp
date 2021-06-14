// Input:
// str : geeksforgeeks

// output:
// count[‘e’] = 4 
// count[‘g’] = 2 
// count[‘k’] = 2 

//count the duplicate elements : in given string

#include<iostream>
#include<cstring>
using namespace std;

//Brute force : 
// void count_duplicates(string str){
    
// }

int main(){
    string str;
    cout<<"Enter the input string : ";
    cin>>str;

    // count_duplicates(str);

    int start=0;
    int end=str.size()-1;

    int count=0;
    for(int idx=0;idx<str.size();idx++){
        for(int jdx=idx+1;jdx<str.size();jdx++){
            if(str[idx]==str[jdx]){
                count++;
            }
        }
        if(count>1){
            cout<<str[idx]<<" :"<<count<<endl;            
        }
        count=0;
    }


    return 0;
}
//Boyes moore algorithm for pattern searching : 

//works in 3 steps : 
//1.  construct Bad match table
//2.  compare pattern to the text starting from the rightmost character in pattern
//3.  when mismatch occures you shift the pattern to the right corresponding to the value 
//    in the bad match table.
//value=lenght-index-1;


#include<iostream>
#include<cstring>
using namespace std;

int search_pattern(string pattern, string txt){



}

int main(){
    string pattern;
    cout<<"Patter need to search : ";
    cin>>pattern;

    string txt;
    cout<<"Text for searching pattern :  ";
    cin>>txt;

    cout<<"Pattern found at a :  "<<search_pattern(pattern,txt);

    return 0;
}
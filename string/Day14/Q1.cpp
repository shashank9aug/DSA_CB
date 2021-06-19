// Pattern searching is an important problem in computer science. When we do search 
// for a string in notepad/word file or browser or database,
// pattern searching algorithms are used to show the search results. 

#include<iostream>
#include<string>
using namespace std;

//Naive approach : 
void pattern_search(string txt,string pat){
    for(int i=0;i<(txt.size()-pat.size());i++){
        int j=0;
        for(j=0;j<pat.size();j++){
            if(txt[i+j]!=pat[j]){
                break;
            }
        }
        
        //if j pointed to last character of pat string 
        if(j==pat.size()){
            cout<<"Pattern found : "<<i<<endl;
        }
    }
}


//Optimised methon : Robin karp algorithm.




int main(){
    string txt;
    cout<<"Enter the text string : ";
    // cin.getline(txt,100,'\0');  
    getline(cin,txt);
    cin>>txt;

    string pat;
    cout<<"Enter pattern string need to search : ";
    cin>>pat;

    // pattern_search(txt,pat);

    return 0;
}
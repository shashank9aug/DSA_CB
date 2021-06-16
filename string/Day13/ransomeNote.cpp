// leetcode ransome-note problem

// Input: ransomNote = "a", magazine = "b"
// Output: false

#include<iostream>
#include<cstring>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int letter[26]={0};
        
    //mark all the letters of ransomeNote 
    for(int i=0;i<ransomNote.size();i++){
        letter[ransomNote[i]-'a']++;
    }
        
    //remove letter which can formed from magazine
    for(int i=0;i<magazine.size();i++){
        letter[magazine[i]-'a']--;
    }
        
    //check whether letter have any ransomeNote letter
    for(int i=0;i<26;i++){
        if(letter[i]>0){
            return false;
        }
    }
    return true;
}


int main(){
    string raisomNote,magzine;
    cout<<"Enter rainsomNote and magzine string : ";
    cin>>raisomNote>>magzine;
 
    bool ans=canConstruct(raisomNote,magzine);

    if(ans){
        cout<<"raisomNote are in magzine"<<endl;
    }
    else{
        cout<<"raisomNote are not in magzine"<<endl;
    }
}
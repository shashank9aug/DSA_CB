//count and say : 

// Input: n = 4
// Output: "1211"
// Explanation:
// countAndSay(1) = "1"
// countAndSay(2) = say "1" = one 1 = "11"
// countAndSay(3) = say "11" = two 1's = "21"
// countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"


//sequence : 
// n=1  :  "1"
//n=2   :  "11"
//n=3   :  "2 times 1"  :  "21"
//n=4   :  "1 times 2 + 1 times 1"  : "1211"
//n=5   :  "1 times 1 + 1 times 2 + 2 times 1"  :  "111221" 

#include<iostream>
#include<cstring>
using namespace std;

string count_and_say(int num){
    if(num==1){
        return "1";
    }
    if(num==2){
        return "11";
    }
    //for n>2
    //start iteration from 2
    string s="11";
    for(int idx=3;idx<=num;idx++){
        //We are just adding delimeter at the end of string
        s=s+'@';
        //string t to store next iteration value 
        string t="";

        //counter to update number of times ith item occur
        int count=1;
        for(int jdx=1;jdx<s.length();jdx++){
            //check no of times
            if(s[jdx]==s[jdx-1]){
                count++;
            }
            //unequal previous occurrence 
            else{
                //update t string by occurence
                t=t+to_string(count);
                //then add item
                t=t+s[jdx-1];
                count=1;
            }
        }
      s=t;  
    }
    return s;
}


int main(){
    int num;
    cout<<"Enter the number : ";
    cin>>num;

    cout<<"output string : "<<count_and_say(num)<<endl;


    return 0;
}
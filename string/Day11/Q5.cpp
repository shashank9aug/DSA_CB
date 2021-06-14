// given s1 = ABCD and s2 = CDAB, return true,
// given s1 = ABCD, and s2 = ACBD , return false


#include<iostream>
#include<cstring>
using namespace std;

bool check_rotation(string str1,string str2){
    if(str1.size()!=str2.size()){
        return false;
    }
    else{
        int start=0,end=str2.size()-1;
        
        bool flag=false;

        while(start<str1.size() and end>=0){
            if(str1[start]==str2[end]){
                start++;
                end--;
            }
            else{
                flag=false;
                return flag;
            }
        }
        flag=1;
        return flag;
    }
}


int main(){
    string str1,str2;
    cout<<"Enter string1 and string2 : ";
    cin>>str1>>str2;

    bool ans=check_rotation(str1,str2);
    if(ans){
        cout<<"Strings are rotation of each other."<<endl;
    }
    else{
        cout<<"Strings are not rotation of each other."<<endl;
    }

    return 0;

}
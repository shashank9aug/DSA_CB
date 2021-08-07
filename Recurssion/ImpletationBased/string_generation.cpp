/*
    we have given mapping of number in which : 
    1->A
    2->B
    3->C
    ....
    26->Z

    we have to generate all the possible strings from set of array elements

    ip : 1234
    1234 -> ABCD
    (12)34 -> LCD
    1(23)4 -> AWD
    12(34) -> not possible 

*/


#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void generateString(char *ip,char *op,int i,int j){
    //Base case :
    if(ip[i]=='\0'){
        op[j]='\0';
        cout<<op<<endl;
        return;
    }

    //IP-OP
    //one digit at time : 
    int digit=ip[i]-'0';
    char ch=digit+'A'-1;
    op[j]=ch;
    generateString(ip,op,i+1,j+1);

    //taking two digit at time : 
    if(ip[i+1]!='\0'){
        int secondDigit=ip[i+1]-'0';
        int no=digit*10+secondDigit;

        if(no<=26){
            ch=no+'A'-1;
            op[j]=ch;
            generateString(ip,op,i+2,j+1);
        }
    }
    return;
}

int main(){
    char ip[100];
    cout<<"Enter input string : ";
    cin>>ip;

    char op[100];

    generateString(ip,op,0,0);

    return 0;
}
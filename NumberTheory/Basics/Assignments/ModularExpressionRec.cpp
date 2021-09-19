/*

PS D:\GitHub\Algo++\NumberTheory\Basics\Assignments> ./a.exe
2 5 13
6

*/

#include<iostream>
#include<math.h>
using namespace std;


int exponentMod(int a,int b,int c){
    //Base case :
    if(a==0){
        return 0;
    }
    //a^0 = 1
    if(b==0){
        return 1;
    }

    long ans;
    //If b is even : 
    if(b%2==0){
        ans=exponentMod(a,b/2,c);
        ans=(ans*ans)%c;
    }

    //if b is odd : 
    else{
        ans=a%c;
        ans=(ans*exponentMod(a,b-1,c)%c)%c;
    }
    return (int)((ans+c)%c);
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;

    cout<<exponentMod(a,b,c)<<endl;

    return 0;
}
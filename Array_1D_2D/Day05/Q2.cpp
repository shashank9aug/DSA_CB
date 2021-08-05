
// Input: N = 10
// Output: 3628800
// Explanation :
// 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

// Input : 100
// Output : 933262154439441526816992388562667004-
//          907159682643816214685929638952175999-
//          932299156089414639761565182862536979-
//          208272237582511852109168640000000000-
//          00000000000000

//n! = n*(n-1)*(n-2)*....*1

#include<iostream>
using namespace std;
//Without any constraint like as number value increases factorial value will increased adruptly so 
/*int large_no_factorial(int number){
    int fact=1;
    for(int idx=2;idx<=number;idx++){
        fact=fact*idx;
    }
    return fact;
}*/



int large_no_factorial(int number){

}

int main(){
    int number;
    cin>>number;

    cout<<"Factorial of large number : "<<large_no_factorial(number)<<endl;

    return 0;
}

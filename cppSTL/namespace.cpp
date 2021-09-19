#include<iostream>
// using namespace std;  => cpp just adds all the important scopes or we can say declarations in single namespace

namespace shashank{
    int val=60;
}

int main(){
    int val=50;
    // double val=20;
    std::cout<<val<<std::endl;
    
    std::cout<<shashank::val<<std::endl;
}
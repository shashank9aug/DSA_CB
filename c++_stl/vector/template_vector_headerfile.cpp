//Implementation of custom header file with  : 

#include<iostream>
#include "vector_template.h"
using namespace std;

int main(){

    //Basically we are not able to specify datatypes of vector class because 
    //that is implemented using templates of c++ vector -> templated class 
    //vector<..>..

    Vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.pop_back();
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(60);
    v.push_back(60);
    v.push_back(60);
    v.push_back(60);
    v.push_back(60);

    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;

    for(auto i=0;i<v.size();i++){
        cout<<v[i]<<",";
    }

    return 0;
}
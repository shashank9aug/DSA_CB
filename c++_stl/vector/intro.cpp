//vectors : C++ Stl container

//it's dynamic array which is defined under #include<vecor> header file

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v{1,2,3,4,5};
    
    //vector with all elements is zeroes
    vector<int>b(5,0);

    //iterator over array
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<",";
    }
    cout<<endl;
   
    //auto is keyword which will detect the type of datatype itself    
    for(auto it=b.begin();it!=b.end();it++){
        cout<<*it<<",";
    }
    cout<<endl;

    //assign a vector having same element as vetor v
    vector<int>c(v.begin(),v.end());
    //for-each loop
    for(auto it:c){
        cout<<it<<",";
    }
    cout<<endl;

}
/*
    PS : given list of n JEE students with mapping of A->10...Z->100

    we have to make array of vectors.
    
    Sort the students according to their marks in rank


$ ./a.exe
5
A 10
B 40
C 30
D 15
E 40
------
40 B
40 E
30 C
15 D
10 A

*/

#include<iostream>
#include<vector>
using namespace std;

class student{
public: 
    string name;
    int marks;
};


void bucketSort(student s[],int n){
    //assuming marks from 0 to 360
    vector<student>v[360];
    //O(n)
    for(int i=0;i<n;i++){
        //marks grouping
        int m=s[i].marks;
        v[m].push_back(s[i]);
    }


    //iterate over the vector and print the students: 
    for(int i=100;i>=0;i--){
        for(vector<student>::iterator it=v[i].begin();it!=v[i].end();it++){
            cout<<(*it).marks<<" "<<(*it).name <<endl;
        }
    }    
}

int main(){
    student s[100];
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>s[i].name>>s[i].marks;
    }
    cout<<"------"<<endl;
    bucketSort(s,n);

    return 0;

}

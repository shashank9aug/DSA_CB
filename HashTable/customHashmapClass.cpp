#include<iostream>
#include<unordered_map>
using namespace std;

class student{
    public :

    string firstName;
    string lastName;
    int rollno;

    student(string f,string l,int no){
        firstName=f;
        lastName=l;
        rollno=no;
    }

    bool operator==(const student &s){
        return rollno==s.rollno;
    }

};

//Hashfunction : 
class hashFun{
public : 
    //size of memory in bits.
    size_t operator()(const student &s)const{
        return s.first.firstName.length()+s.second.lastName.length();
    }    
};


int main(){
    
    unordered_map<student,int,hashFun>student_map;
    
    student s1("Shashank","Shekhar",30);    
    student s2("Jalaj","chai",44);    
    student s3("Shashank","Shekhar",90);    
    student s4("Sonu","sharma",130); 

    //Add student into student map : 
    student_map[s1]=100;
    student_map[s2]=120;
    student_map[s3]=130;
    student_map[s4]=50;

    //Iterate over all the students : 
    for(auto it:student_map){
        cout<<it.firstName<<" and "<<it.rollno<<endl;
    }

    return 0;
}
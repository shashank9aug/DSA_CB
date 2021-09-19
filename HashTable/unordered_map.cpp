
/*
Banana
Fruit price : Banana is 60
Price is : 22

---------------keys are not in sorted order----------------
Mango and 80
Litchi and 80
Apple and 200
Pineapple and 180
Orange and 90
Banana and 22
------------------
Mango and 80
Litchi and 80
Apple and 200
Pineapple and 180
Orange and 90
Banana and 22

*/

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int>ump;

    //1.Insert : 
    ump.insert(make_pair("Mango",20));
    ump.insert(make_pair("Banana",60));
    ump.insert(make_pair("Litchi",50));

    pair<string,int>p;
    p.first="Apple";
    p.second=200;

    ump.insert(p);

    ump["Orange"] = 90;   


    //Search : 
    string fruit;
    cin>>fruit;

    auto it=ump.find(fruit);
    if(it!=ump.end()){
        cout<<"Fruit price : "<<fruit<<" is "<<ump[fruit]<<endl;
    }
    else{
        cout<<"Fruit is not present."<<endl;
    }

    //erase  : 
    ump.erase(fruit);


    //update the price of fruit :
    ump[fruit]+=22;

    //Another way to fing particular map
    //it stores only unique key only once.
    //find function returns an iterator but count function returns 1/0
    if(ump.count(fruit)){
        cout<<"Price is : "<<ump[fruit]<<endl;
    }
    else{
        cout<<"Fruit is not present."<<endl;
    }

    ump["Litchi"]=80;
    ump["Pineapple"]=180;
    ump["Mango"]=80;

    //iterate over all the key value pair : 
    for(auto it=ump.begin();it!=ump.end();it++){
        cout<<it->first<<" and "<<it->second<<endl;
    }

    cout<<"------------------"<<endl;

    //For each looop : 
    for(auto it:ump){
        cout<<it.first<<" and "<<it.second<<endl;
    }

}
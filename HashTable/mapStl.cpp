/*

PS D:\GitHub\Algo++\HashTable> ./a.exe
Banana
Fruit price : Banana is 20
Price is : 22

// Fruits are sorted in lexicographical order.

Apple and 120
Banana and 22
Litchi and 80
Mango and 80
Pineapple and 180
------------------
Apple and 120
Banana and 22
Litchi and 80
Mango and 80
Pineapple and 180


*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string,int>mp;

    //Insert : 
    mp.insert(make_pair("Mango",10));

    pair<string,int>p;
    p.first="Apple";
    p.second=120;

    mp.insert(p);

    mp["Banana"]=20;

    //Search : 
    string fruit;
    cin>>fruit;

    auto it=mp.find(fruit);
    if(it!=mp.end()){
        cout<<"Fruit price : "<<fruit<<" is "<<mp[fruit]<<endl;
    }
    else{
        cout<<"Fruit is not present."<<endl;
    }

    //erase  : 
    mp.erase(fruit);


    //update the price of fruit :
    mp[fruit]+=22;

    //Another way to fing particular map
    //it stores only unique key only once.
    //find function returns an iterator but count function returns 1/0
    if(mp.count(fruit)){
        cout<<"Price is : "<<mp[fruit]<<endl;
    }
    else{
        cout<<"Fruit is not present."<<endl;
    }

    mp["Litchi"]=80;
    mp["Pineapple"]=180;
    mp["Mango"]=80;

    //iterate over all the key value pair : 
    for(auto it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<" and "<<it->second<<endl;
    }

    cout<<"------------------"<<endl;

    //For each looop : 
    for(auto it:mp){
        cout<<it.first<<" and "<<it.second<<endl;
    }


    return 0;
}
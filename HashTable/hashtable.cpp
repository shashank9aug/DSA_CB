/*

//without rehashing

PS D:\GitHub\Algo++\HashTable> ./a.exe
Bucket 0->      
Bucket 1->coke->
Bucket 2->cheese->
Bucket 3->Burger->
Bucket 4->
Bucket 5->
Bucket 6->noodles->pizza->

//rehashing :
*/


#include<iostream>
#include<cstring>
#include "hashtable.h"
using namespace std;

int main(){
    HashTable<int>priceMenu;

    priceMenu.insert("Burger",120);
    priceMenu.insert("pizza",100);
    priceMenu.insert("noodles",150);
    priceMenu.insert("cheese",20);
    priceMenu.insert("coke",50);

    priceMenu.print();

    int *price=priceMenu.search("pizza");
    if(price==NULL){
        cout<<"NOT Found."<<endl;
    }
    else{
        cout<<"Price is : "<<*price<<endl;
    }

    //MAP

    //Insert
    priceMenu["Dosa"]=60;
    priceMenu["Dosa"]+=10;
    //search :
    cout<<"price of Dosa : ";
    cout<<priceMenu["Dosa"]<<endl;

    return 0;
}
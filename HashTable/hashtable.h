/*
    Implement a HashTable. 
    using separate chaining technique.


*/

#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class node{
public : 
    string key;
    T value;
    node<T>*next;

    node(string key,T val){
        this->key=key;
        value=val;        
        next=NULL;
    }

    ~node(){
        if(next!=NULL){
            delete next;
        }
    }   
};

template<typename T>
class HashTable{
    node<T>**table;
    int currentSize;
    int tableSize;

    int hashFun(string key){
        int idx=0;
        int pow=1;

        for(int j=0;j<key.size();j++){
            idx=idx + (key[j]*pow)%tableSize;
            idx=idx%tableSize;
            pow=(pow*27)%tableSize;
        }
        return idx;
    }
    
    void rehash(){
        node<T>**oldTable=table;
        int oldTableSize=tableSize;
        tableSize=2*tableSize;  //Approximation that find next prime number.
        table=new node<T>*[tableSize];

        for(int i=0;i<tableSize;i++){
            table[i]=NULL;
        }
        currentSize=0;

        //shift the elements from old table to new table.

        for(int i=0;i<oldTableSize;i++){
            node<T>*temp=oldTable[i];
            while(temp!=NULL){
                insert(temp->key,temp->value);
                temp=temp->next;
            }
            //Recurssive Destructor Call : to delete old table items. 
            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
        } 
        delete [] oldTable;
    }

public : 
    HashTable(int ts=7){
        tableSize=ts;
        table=new node<T>*[tableSize];
        currentSize=0;
        for(int i=0;i<tableSize;i++){
            table[i]=NULL;
        }
    }

    //O(1) insertion.
    void insert(string key,T value){
        int idx=hashFun(key);
        node<T>*n=new node<T>(key,value);
        //Insert at head of linkedlist with id=idx;
        n->next=table[idx];
        table[idx]=n;
        currentSize++;

        //rehashing : 
        float loadFactor=currentSize/(1.0*tableSize);

        if(loadFactor>0.7){
            rehash();
        }
    }

    void print(){
        for(int i=0;i<tableSize;i++){
            cout<<"Bucket "<<i<<"->";
            node<T>*temp=table[i];
            while(temp!=NULL){
                cout<<temp->key<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

    
    //O(1) search.
    T* search(string key){
        int idx=hashFun(key);
        node<T>*temp=table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return &temp->value;
            }
            temp=temp->next;
        }
        return NULL; //its pointer so we are taking T as T*
    }    

    T &operator[](string key){
        T*f=search(key);
        if(f==NULL){
            //Insert key,value(garbage) in the hashmap
            T garbage;
            insert(key,garbage);
            f=search(key); 
        }
        return *f;
    }

    void erase(string key){

    
    }
    
};
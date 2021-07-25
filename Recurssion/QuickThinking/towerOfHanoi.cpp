/*
    we have n discs at location src and we have to shift discs to des using helper

    rule : 
        move all disc from A to C
        pick 1 disk at time
        cannot place bigger disk on small disk

    We have to print the each step we will follow to move disk

*/


#include<iostream>
using namespace std;

void move(int n,char src,char helper,char dest){
    //base case : 
    if(n==0){
        return;
    }

    //rec case :
    //move 1 disc at time :

    move(n-1,src,dest,helper);
    
    //shift the remaining disc
    cout<<"Shift disk : "<<n<<" from "<<src<<" to "<<dest<<endl;
    
    move(n-1,helper,src,dest);

}

int main(){
    int n;
    cout<<"Enter number of disks : ";
    cin>>n;

    move(n,'A','B','C');

    return 0;
}
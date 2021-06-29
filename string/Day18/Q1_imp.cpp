//we have to create function to find number of person who could not get computer

/*
Input : n : number of computer in cafe
       seq : - all the letters are in capital
             - seq.first=arival of person
             - seq.second=departure of person

       (No person can come more than two times)

Output : (>=1) no of person moved outside without using computer
         (=0) all person get chance to use computer
*/

#include<iostream>
using namespace std;

int runCustomerSimulation(int n,string seq){
    //no of customer may occur
    int occ[26]={0};

    int ans=0;
    int occupy=0;    
    for(int i=0;i<seq.size();i++){
        //check seat is vaccant or not for seq[i];

        int index=seq[i]-65;
        //person appeared or not
        if(occ[index]==0){
            //mark as appear
            occ[index]=1;

            //check for vaccant computer in cafe
            if(occupy<n){
                occupy++;
                //mark as he get chance to use computer
                occ[index]=2;
            }
            //otherwise seq[i] haven't get chance to use computer
            else{
                ans++;
            } 
        }

        //else seq[i] appeared again then mark According to if he get chance or not
        else{
            //person was using computer previously
            if(occ[index]==2){
                occupy--;
            }
            occ[index]==0;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number of computer : ";
    cin>>n;

    string seq;
    cout<<"Enter customer arival and departure : ";
    cin>>seq;

    //check occurence of person can not be more than two times
    int h[26]={0};
    for(int i=0;i<seq.length();i++){
        h[seq[i]-65]++;
    }

    // for(int i=0;i<26;i++){
    //     cout<<h[i]<<",";
    // }

    for(int i=0;i<26;i++){
        if(h[i]>2){
            cout<<"-1";
            return 0;
        }
    }
    
    cout<<runCustomerSimulation(n,seq)<<endl;

    return 0;    

}

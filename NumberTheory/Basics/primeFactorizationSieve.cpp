#include<iostream>
#include<vector>
using namespace std;

vector<int> primeSeive(int prime[],int n){
    prime[0]=prime[1]=0;
    prime[2]=1;

    //Mark all odd no as prime :
    for(int i=3;i<=n;i+=2){
        prime[i]=1;
    }

    for(int i=3;i<=n;i+=2){
        if(prime[i]==true){
            //Mark all the multiples of that number as not prime :
            for(int j=i*i;j<i;j=2*i){
                prime[j]=0;
            }
        }
    }

    vector<int>primeNo;
    primeNo.push_back(2);
    for(int i=3;i<n;i+=2){
        if(prime[i]==1){
            primeNo.push_back(i);
        }
    }
    return primeNo;
}

vector<int>factorize(int no,vector<int>&prime){
    vector<int>factors;

    int i=0;
    int p=prime[0];

    //no=24  5*5=25>24
    while(p*p<=no){
        if(no%p==0){
            factors.push_back(p);
            while(no%p==0){
                no=no/p;
            }
        }
        // go to the next position 
        i++;
        p=prime[i];
    }

    if(no!=1){
        factors.push_back(no);
    }

    return factors;
}

int main(){
    int n;
    cin>>n;
    int p[n+1]={0};
    vector<int>prime=primeSeive(p,n);

    int t;
    cin>>t;
    while(t--){
        int no;
        cin>>no;

        vector<int>factors=factorize(no,prime);

        for(auto v:factors){
            cout<<v<<", "<<endl;
        }
    }
    return 0;
}
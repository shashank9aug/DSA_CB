/*

PS D:\GitHub\Algo++\NumberTheory\Basics> ./a.exe
1
60
12

*/

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

int countDivisors(int no,vector<int> prime){
    int i=0;
    int p=prime[0];
    int ans=1;

    while(p*p<=no){
        if(no%p==0){
            int count=0;
            while(no%p==0){
                count++;
                no=no/p;
            }
            ans=ans*(count+1);
        }
        i++;
        p=prime[i];
    }
    if(no!=1){
        ans=ans*2;
    }
    return ans;
}

int main(){
    int p[100]={0};
    vector<int>primeNo=primeSeive(p,100);

    int t;
    cin>>t;

    while(t--){
        int no;
        cin>>no;

        int divs=countDivisors(no,primeNo);

        cout<<divs<<endl;
    }
}
/*
    we have given n to and we have to return nth prime number : 

constraints : 
1=<t<10^3
1<n<10^6

*/

#include<iostream>
#include<vector>
using namespace std;

vector<int>ans;
void primeSeive(int *prime){

    //mark all odd numbers as prime no : 
    for(int i=3;i<=1000000;i+=2){
        prime[i]=1;
    }

    //Seive : 
    for(long long i=3;i<=1000000;i+=2){
        //if Current element is not marked : (it is prime)
        if(prime[i]==1){
            //mark all the multiples of i as not prime :
            for(long long j=i*i;j<=1000000;j=j+i){
                prime[j]=0;
            }
        }
    }
    prime[2]=1,prime[0]=prime[1]=0;

	for(long long i=2;i<=1000000;i++){
		if(prime[i]==1){
			ans.push_back(i);
		}
	}
}

int main(){
    int t;
    cin>>t;
    int prime[1000005]={0};

    primeSeive(prime);
    
    while(t--){
        int n;
        cin>>n;

        cout<<ans[n-1]<<endl;
    }
    return 0;
}
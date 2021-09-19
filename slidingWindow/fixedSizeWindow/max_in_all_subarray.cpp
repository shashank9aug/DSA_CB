/*

KIIT@Shashank-Shekhar MINGW64 /d/GitHub/Algo++/slidingWindow (master)
$ ./a.exe
8
1 3 -1 -3 5 3 6 7
Enter window size : 3
3 3 5 5 6 7 

*/


#include<bits/stdc++.h>
using namespace std;

vector<int> slidingMaximum(vector<int> nums, int k) {
    vector<int> output;
    int i=0;
    int j=0;
    deque<int> l;
        
    while(j<nums.size())
    {
        if(l.empty()){   //!=0
            l.push_back(nums[j]);   
        }
        else
        {
            while(!l.empty() && l.back()<nums[j]){
                l.pop_back();
            }
            l.push_back(nums[j]);               
        }
        if(j-i+1<k){
            ++j;
        }
        else if(j-i+1==k)
        {
            output.push_back(l.front());
            if(nums[i]==l.front()){
                l.pop_front();
            }
            ++i;
            ++j;
        }
    }
    return output;
}




int main()
{
    int n;
    cin>>n;

    vector<int>num;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        num.push_back(d);
    }
    int k;
    cout<<"Enter window size : ";
    cin>>k;

    vector<int>ans=slidingMaximum(num,k);

    // Print the list
    for(auto a : ans)
        cout << a << " ";
    cout << endl;
    return 0;
}
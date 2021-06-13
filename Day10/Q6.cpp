// Maximum area of histogram : 

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> NGL(int array[],int size){
    vector<int>v;
    stack<pair<int,int>>st;

    int sudo=-1;
    for(int idx=0;idx<size;idx++){
        if(st.size()==0){
            v.push_back(sudo);
        }
        else if(st.size()>0 && st.top().first>array[idx]){
            v.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first<=array[idx]){
            while(st.size()>0 && st.top().first<=array[idx]){
                st.pop();
            }
            if(st.size()==0){
                v.push_back(sudo);
            }
            else{
                v.push_back(st.top().second);
            }
        }
        st.push({array[idx],idx});
    }

    for(int idx=0;idx<size;idx){
        v[idx]=idx-v[idx];
    }

    return v;
}

vector<int> NGR(int array[],int size){
    vector<int>v;
    stack<pair<int,int>>st;

    int sudo=size;
    for(int idx=size-1;idx>=0;idx--){
        if(st.size()==0){
            v.push_back(sudo);
        }
        else if(st.size()>0 && st.top().first>array[idx]){
            v.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first<=array[idx]){
            while(st.size()>0 && st.top().first<=array[idx]){
                st.pop();
            }
            if(st.size()==0){
                v.push_back(sudo);
            }
            else{
                v.push_back(st.top().second);
            }
        }
        st.push({array[idx],idx});
    }
    reverse(v.begin(),v.end());
    for(int idx=0;idx<size;idx){
        v[idx]=idx-v[idx];
    }

    return v;
}




int main(){
    int size;
    cout<<"Enter the no of buildings : ";
    cin>>size;

    int array[size];
    cout<<"Enter the height of buildings : ";
    for(int idx=0;idx<size;idx++){
        cin>>array[idx];
    }

    int max_area=INT32_MIN;

    vector<int>left=NGL(array,size);
    // vector<int>right=NGR(array,size);

    // vector<int>width;

    // for(int idx=0;idx<size;idx++){
    //     width[idx]=(right[idx]-left[idx]-1);
    // }

    // vector<int>area;

    // for(int idx=0;idx<size;idx++){
    //     area[idx]=width[idx]*array[idx];
    // }

    // //Max area
    // for(int idx=0;idx<size;idx++){
    //     max_area=max(max_area,area[idx]);
    // }    

    // cout<<"Maximum area of histogram : "<<max_area<<endl;

    for(int idx=0;idx<size;idx++){
        cout<<left[idx]<<",";
    }

    return 0;
}
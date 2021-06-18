//A person standing at the origin and he wants to get the location of all
//the cabs around him in sorted order

//person has coordinates of all the cabs around him

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//comparator function
bool compare(pair<int, int> p1, pair<int, int> p2)
{
    int d1 = p1.first * p1.first + p1.second * p1.second;
    int d2 = p2.first * p2.first + p2.second * p2.second;

    if (d1 == d2)
    {
        return p1.first < p2.first;
    }

    return d1 < d2;
}

int main()
{
    int n;
    cout << "Enter the no of cabs : ";
    cin >> n;

    vector<pair<int, int>> v;
    //this is how we cannot take input inside pair inside vector
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i].first >> v[i].second;
    // }

    for(int i=0;i<n;i++){
        int x;
        int y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(), v.end(), compare);

    for(auto i:v){
        cout<<i.first<<","<<i.second<<","<<endl;
    }
}
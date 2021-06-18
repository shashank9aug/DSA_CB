//A person standing at the origin and he wants to get the location of all
//the cabs around him in sorted order

//person has coordinates of all the cabs around him

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//class for vector<class>v

class car
{
public:
    string car_name;
    int x;
    int y;

    car()
    {
        
    }

    car(string n, int x, int y)
    {
        car_name = n;
        this->x = x;
        this->y = y;
    }

    int dist()
    {
        return x * x + y * y;
    }
};

bool compare(car A, car B)
{
    int da = A.dist();
    int db = B.dist();

    //sorting based on name length of car if da==db
    if (da == db)
    {
        return A.car_name.length() > B.car_name.length();
    }
    return da < db;
}

int main()
{
    int n;
    cout << "Enter the number of car : ";
    cin >> n;

    vector<car> c;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        string name;
        cin >> name >> x >> y;
        car temp(name, x, y);
        c.push_back(temp);
    }

    sort(c.begin(), c.end(), compare);

    for(auto x:c){
        cout<<"car "<<x.car_name<<","<<x.x<<","<<x.y<<endl;
    }

    return 0;

}
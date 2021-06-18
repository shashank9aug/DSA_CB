
//v.push_back()   : it's memory cost

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4};

    for (auto i : v)
    {
        cout << i << ",";
    }
    cout << endl;

    //return size of vector:
    cout << "Size of vector v : " << v.size() << endl;

    //size of underlying vector:
    cout << "Capacity of vector v : " << v.capacity() << endl;

    //max no of elements a vector can hold in wrost case a/c to memory available in RAM
    cout << "Max size of vector v : " << v.capacity() << endl;

    //we push back no in vector
    v.push_back(20);
    cout << "Size of vector v : " << v.size() << endl;

    cout << "capacity of vector v : " << v.capacity() << endl;

    for (auto i : v)
    {
        cout << i << ",";
    }
    cout << endl;
    //     1,2,3,4,
    // Size of vector v : 4
    // Capacity of vector v : 4
    // Max size of vector v : 4
    // Size of vector v : 5
    // capacity of vector v : 8
    // 1,2,3,4,20,

    //why capcity doubled after push_back(12)??

    //pop_back()  : O(1) TC
    v.pop_back();

    for (auto i : v)
    {
        cout << i << ",";
    }
    cout << endl;
    //insert element in the middle :
    v.insert(v.begin() + 2, 20);

    cout << "After inserting elements : ";
    for (auto i : v)
    {
        cout << i << ",";
    }
    cout << endl;

    //erasing some elements :
    v.erase(v.begin() + 2);

    cout << "Vector after erasing middle elements : ";
    for (auto i : v)
    {
        cout << i << ",";
    }
    cout << endl;

    //we can erase range of elements :
    v.erase(v.begin() + 2, v.begin() + 4);

    cout << "Vector after erasing range of elements : ";
    for (auto i : v)
    {
        cout << i << ",";
    }
    cout << endl;

    cout << "Size of vector : " << v.size() << endl;
    cout << "capacity of vector : " << v.capacity() << endl;

    //resize function
    v.resize(18);
    cout << "Size of vector : " << v.size() << endl;
    cout << "capacity of vector : " << v.capacity() << endl;

    //clear / erase all the elements
    v.clear();

    if (v.empty())
    {
        cout << "Vector is empty" << endl;
    }

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (auto i : v)
    {
        cout << i << ",";
    }
    cout << endl;

    cout << "Front elements of vector : " << v.front() << endl;
    cout << "back elements of vector : " << v.back() << endl;

    //reserve : it will reserve the capacity of vector how much we want to use
    //it basically solves the problem of doubling of vector size when we just push_back(x)

    v.reserve(100);

    v.push_back(50);

    v.resize(30);
    cout << "Size of vector : " << v.size() << endl;
    cout << "capacity of vector : " << v.capacity() << endl;

    v.push_back(60);
    v.push_back(70);
    v.push_back(80);

    for (int x : v)
    {
        cout << x << ",";
    }
    cout << endl;
    cout << "Size of vector : " << v.size() << endl;
    cout << "capacity of vector : " << v.capacity() << endl;
}
//Bishnu and soldiers

//given :
/*
    N=7  (total number of soldirs)
    arr[]={1,2,3,4,5,6,7}  (strength of soldirs)
    Q = 3  (number of rounds)
    3      (round 1 energy)
    10     (round 2 energy)  
    2      (round 3 energy)

    output : 
    n1 (number of soldirs that bishnu beats) , n2 (cummulative sum of the soldirs n1 soldiers)

    3,6
    7,28
    2,3
*/

#include <iostream>
#include <algorithm>
using namespace std;

void soldiers_beat(int n, int arr[], int strength)
{
    //we have to count the number of arr[i] less than or equal to streangth[0...n]
    int n1 = 0;
    int n2 = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] <= strength)
        {
            n1++;
            n2 += arr[j];
        }
    }
    //cummulative sum
    // for(int j=0;j<n1;j++){
    //     n2+=arr[j];
    // }
    cout << n1 << " " << n2 << endl;
}

int main()
{
    int n;
    cout << "Enter the number of soldirs : ";
    cin >> n;

    int arr[n];
    cout << "soldiers streangth : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int q;
    cout << "Enter the number of rounds : ";
    cin >> q;

    while (q--)
    {
        int strength;

        cin >> strength;
        soldiers_beat(n, arr, strength);
    }
    return 0;
}

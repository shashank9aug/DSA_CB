/*
    we have given string in which we have to replace : pi = 3.14

    eg : xgapigopi = xga3.14go3.14

$ ./a.exe
xpiapighpi
x3.14a3.14gh3.14
*/

#include <iostream>
using namespace std;

void replacePi(char arr[], int i)
{
    //Base Case :
    if (arr[i] == '\0' or arr[i + 1] == '\0')
    {
        return;
    }

    //rec case :
    // if we get pi
    if (arr[i] == 'p' and arr[i + 1] == 'i')
    {
        //shifing and replacement with 3.14
        int j = i + 2;

        //take j to the end of array
        while (arr[j] != '\0')
        {
            j++;
        }

        //realign value : shifting right to left
        while (j >= i + 2)
        {
            arr[j + 2] = arr[j];
            j--;
        }
        //replacement plus recurssive call for remaining part :
        arr[i] = '3';
        arr[i + 1] = '.';
        arr[i + 2] = '1';
        arr[i + 3] = '4';

        replacePi(arr, i + 4);
    }
    //if arr[i] is not p and i
    else
    {
        replacePi(arr, i + 1);
    }

    return;
}

int main()
{
    char c[100];
    cin >> c;

    replacePi(c, 0);

    cout << c << endl;
}
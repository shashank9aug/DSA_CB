//Considerig all the input characters are capital letters :

//SHASHANK
// S -> 7777
// H -> 44
// A -> 2
// N -> 66
// K -> 55

// Enter the input string : SHASHANK
// mobile numeric keypad : 777744277774426655

// So we have to create an array which will contain all the numeric keypad value of char

#include <iostream>
using namespace std;

string numeric_keypad(string str,string value[])
{
    string ans;

    for (int i = 0; i < str.size(); i++)
    {
        if(str[i]==' '){
            ans+='0';
        }
        else{
            int num=(str[i]-'A');
            ans+=value[num];
        }
    }
    return ans;
}

int main()
{
    string str;
    cout << "Enter the input string : ";
    cin >> str;

    string value[] = {"2", "22", "222",
                      "3", "33", "333",
                      "4", "44", "444",
                      "5", "55", "555",
                      "6", "66", "666",
                      "7", "77", "777", "7777",
                      "8", "88", "888",
                      "9", "99", "999", "9999"};
    cout << "mobile numeric keypad : " << numeric_keypad(str,value) << endl;

    return 0;
}
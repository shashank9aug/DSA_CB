/*
    We will have string as input with both letters and digits 

    we will have to print all the possible permutation with upper case change 

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

*/

#include <iostream>
#include <string>
using namespace std;

void letterCasePerm(string ip, string op)
{
    //Base case :
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }

    //check ip[0] == alphabet or not
    if (isalpha(ip[0]))
    {
        string op1 = op;
        string op2 = op;

        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));

        ip.erase(ip.begin()+0);

        letterCasePerm(ip,op1);
        letterCasePerm(ip,op2);
    }
    else{
        string op1=op;

        op1.push_back(ip[0]);
        ip.erase(ip.begin()+0);

        letterCasePerm(ip,op1);
    }

    return;
}

int main()
{
    string ip;
    cout << "Enter input string : ";
    cin >> ip;

    string op;

    letterCasePerm(ip, op);

    return 0;
}

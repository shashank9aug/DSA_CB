//Add char from front to make string pallindrome

/*
Approach : check for pallindrome if it shows false then erase char from end until it 
           untill it became pallindrome.
           then add that string from front.
*/

#include <iostream>
#include <string>
using namespace std;

//check string isPallindrome or not
bool isPallindrome(string str)
{
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
            break;
        }
    }
    return true;
}

//make string pallindrome after adding char from front
string make_pallindrome(string str)
{
    string ans = "";
    int flag = 1;
    int count = 0;
    int i = 0;
    while (i < str.length())
    {
        if (isPallindrome(str))
        {
            flag = 1;
            break;
        }
        else
        {
            ans += str[str.length() - 1];
            count++;
            str.erase(str.begin() + str.length() - 1);

        }
    }

    ans.append(str);
    // str.append(ans);
    // for(int i=0;i<ans.length();i++){
    //     ans 
    // }

    if (flag)
    {
        cout<<count<<endl;
    }

    return str;
}

int main()
{
    string str;
    cout << "Enter string to make it pallindrome : ";
    cin >> str;

    cout << "Pallindromic string : " << make_pallindrome(str) << endl;

    return 0;
}
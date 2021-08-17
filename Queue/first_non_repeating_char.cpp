/*
    First non-repeating character in running stream of character.

    i/p : a,a,b,c,c,b,d......
    o/p :a,-1,b,b,b,-1,d... 


a  a  b c b c d.
a -1 b b c -1 d 

*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<char> q;
    char ch;
    cin>>ch;
    int freq[27] = {0};
    while (ch != '.')
    {

        q.push(ch);

        freq[ch - 'a']++;

        //query :
        while (!q.empty())
        {
            int idx = q.front() - 'a';
            if (freq[idx] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << " ";
                break;
            }
        }
        //q is empty :
        if (q.empty())
        {
            cout << "-1" << " ";
        }
        cin >> ch;
    }
    return 0;
}
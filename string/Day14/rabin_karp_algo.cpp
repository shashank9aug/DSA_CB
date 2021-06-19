#include <bits/stdc++.h>
using namespace std;

int main()
{
    string txt = "AABAACBAA", pat = "BAA";

    //hash of pat and txt 0 initially
    int hpat = 0, htxt = 0;

    //no of characters 
    int d = 26;

    //larger prime number for taking modulus of hash code 
    int p = 5381;

    //calculate hashcode of pattern
    for (int i = 0; i < pat.size(); i++)
    {
        hpat *= d;
        hpat = hpat + (((pat[i] - 'A' + 1)) % p);
    }

    //matching pattern  with txt value
    int l = 0, r = 0;
    while (r < txt.size())
    {
        //htxt*26
        htxt = htxt * d;

        //txt[i]-'A'+1 = character value    
        htxt = htxt + ((txt[r] - 'A' + 1) % p);

        //(r-l+1) i.e: length of sliding wheel  
        if (r - l + 1 == pat.size())
        {   
            if (htxt == hpat)
                cout << "Match at " << l<<endl;
            
            //rolling the hash
            htxt = htxt - (((txt[l] - 'A' + 1) * pow(d, r - l)));
            l++;
        }
        r++;
    }
    return 0;
}
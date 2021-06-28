//  Generate all the possible 

/*

Rules for IPV4 : (.)seperated
->No leading 0's
->Ranges of Number(0-255)
->should have exactly 4 cells
->should have an INT in each cell
-> eg : 255.192.30.70

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Naive approach : O(N^3)

// Function checks whether IP digits
// are valid or not.
int is_valid(string ip)
{
    // Splitting by "."
    vector<string> ips;
    string ex = "";
    for (int i = 0; i < ip.size(); i++) {
        if (ip[i] == '.') {
            ips.push_back(ex);
            ex = "";
        }
        else {
            ex = ex + ip[i];
        }
    }
    ips.push_back(ex);
 
    // Checking for the corner cases
    // cout << ip << endl;
    for (int i = 0; i < ips.size(); i++) {
        // cout << ips[i] <<endl;
        if (ips[i].length() > 3
            || stoi(ips[i]) < 0
            || stoi(ips[i]) > 255)
            return 0;
 
        if (ips[i].length() > 1
            && stoi(ips[i]) == 0)
            return 0;
 
        if (ips[i].length() > 1
            && stoi(ips[i]) != 0
            && ips[i][0] == '0')
            return 0;
    }
    return 1;
}
 
// Function converts string to IP address
vector<string> generate_ipV4(string ip)
{
    int l = ip.length();
 
    // Check for string size
    if (l > 12 || l < 4) {
        cout << "Not Valid IP Address";
    }
 
    string check = ip;
    vector<string> ans;
 
    // Generating different combinations.
    for (int i = 1; i < l - 2; i++) {
        for (int j = i + 1; j < l - 1; j++) {
            for (int k = j + 1; k < l; k++) {

            //generating 3 (.) seprated string using substr function
                
                check = check.substr(0, k) + "."
                        + check.substr(k, l - k + 2);
                // cout<<check<<endl;
                check = check.substr(0, j) + "."
                        + check.substr(j, l - j + 3);
                // cout<<check<<endl;

                check = check.substr(0, i) + "."
                        + check.substr(i, l - i + 4);
                // cout<<check<<endl;
 
                // cout<< check <<endl;
                // Check for the validity of combination
                if (is_valid(check)) {
                    ans.push_back(check);
                    // std::cout << check << '\n';
                }
                check = ip;
            }
        }
    }
    return ans;
}


int main(){
    string str;
    cout<<"Enter string : ";
    cin>>str;

    vector<string>ans=generate_ipV4(str);
    cout<<"Generated VALID IPV4 : ";

    for(auto i:ans){
        cout<<i<<endl;
    }
    return 0;
}

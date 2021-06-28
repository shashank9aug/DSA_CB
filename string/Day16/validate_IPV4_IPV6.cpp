#include<iostream>
#include<regex>
#include<string>
using namespace std;

string validIPAddress(string IP)
{
    //for IPV4
    regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");

    if (regex_match(IP, ipv4))
    {
        // cout<<"IPv4"<<endl;
        return "IPv4";
    }

    //for IPV6
    regex ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");
    if (regex_match(IP, ipv6))
    {
        // cout<<"IPv6"<<endl;

        return "IPv6";
    }
    return "Neither";
}


int main(){
    string str;
    cout<<"Enter ip address : ";
    cin>>str;

    cout<<validIPAddress(str)<<endl;
}
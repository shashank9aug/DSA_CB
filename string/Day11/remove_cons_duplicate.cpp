
//it will remove consecutive duplicates 

// Input :  geeksforgeeks
// Output :  geksforgeks

#include<iostream>
#include<cstring>
using namespace std;

void remove_duplicate(char str[]){
	int length=strlen(str);

	int prev=0;
	for(int current=1;current<length;current++){
		if(str[current]!=str[prev]){
			prev++;
			str[prev]=str[current];
		}
	}
	str[prev+1]='\0';
	return;
}



int main(){
	char str[100];
	cin.getline(str,100);

	remove_duplicate(str);
	cout<<str<<endl;

	return 0;
}
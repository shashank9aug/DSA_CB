```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    // Day 3 
	// Bitset 
	// int -> 16 bits 
	// char -> 8 bits
	int a[100]; 
	char a[100]; 
 
	// bitset -> 1 bit
 
	bitset<5> bt; // stores 1 or 0 
	cin >> bt; // 10111
 
	// all 
	// true // false
	cout << bt.all(); // returns a true or a false
 
	// any 
	// true 
	cout << bt.any(); // bt -> 10011
 
	// false
	cout << bt.any(); // bt -> 00000
 
	// count 
	// for bt -> 10100
	// prints 2 
	cout << bt.count(); // print the number of set bits
 
	// flip 
	// bt -> 10100
	bt.flip(2); // bt will become 10000
 
	bt.flip(); 
 
	// none 
	// if none is set, then true, else false 
	// bt -> 10000
	cout << bt.none(); // false 
 
	// bt -> 00000
	cout << bt.none(); //true 
 
	// set 
	bt.set(); // 11111 
 
	bt.set(2); // sets the 2nd index
 
	bt.set(2, 0); 
 
 
	// reset 
	bt.reset() // turn all indexes to 0 
 
	bt.reset(2); // turn the 2nd index to 0 
 
	// size 
	cout << bt.size(); // prints 5 
 
	// test 
 
	cout << bt.test(1); // check if the bit is set or not at index  1
 
 
	// Algorithms 
	// sorting 
	// array, vector 
	int n;
	cin >> n; 
	int arr[n]; 
	for(int i = 0;i<n;i++) cin >> arr[i]; 
	// takes n log n 
	sort(arr, arr+n); // in increasing order  
	// sort from 1 to 3 
	sort(arr + 1, arr + 4); 
 
    vector<int> vec(5, 0);
    for(int i = 0;i<n;i++) {
    	cin >> vec[i]; 
    }
 
    sort(vec.begin(), vec.end()); // [)
 
    // vec -> {1, 6, 2, 7, 4} 
    //         0  1  2  3  4 
    // sort it so that only indexes from 1 to 3  
    // final vec -> {1, 2, 6, 7, 4}
    sort(vec.begin() + 1, vec.begin() + 4); // [1, 4)
 
 
    // If I wanna reverse
    // reverse(startIterator, endIterator) -> [)  
    reverse(arr, arr+n); 
 
    reverse(arr + 1, arr + 4); 
 
    reverse(vec.begin(), vec.end()); 
 
    reverse(vec.begin() + 1, vec.begin() + 4); 
 
 
 
    // If i want to fine the maximum elements in any index range 
    // i to j give me the maximum 
 
    // *max_element(firstIterator, lastIterator); 
    int maxi = INT_MIN; 
    for(int k = i;k<=j;k++) {
    	if(a[k] > maxi) {
    		maxi = a[k]; 
    	}
    }
 
 
    int el = *max_element(arr, arr+n); 
    int el = *min_element(arr, arr+n); 
 
 
    int el = *max_element(vec.begin(), vec.end()); 
    int el = *min_element(vec.begin(), vec.end()); 
 
 
 
    // I give you a range and I want you to find the sum in that range 
    // i - j, tell me the sum in that range i to j 
    int sum = 0;
    for(int k = i;k<=j;k++) {
    	sum += arr[k]; 
    }
 
    // accumulate(startIterator, endIterator, initialSum);
    int sum = accumulate(arr, arr+n, 0); 
    int sum = accumulate(vec.begin(), vec.end(), 0);
 
 
    // arr[] -> [1, 6, 7, 1, 2, 1, 3] 
    // x = 1 
    // tell me how many times the element 1 occurs in the array 
    int cnt = 0;
    // O(N)
    for(int i = 0;i<n;i++) {
    	if(arr[i] == x) {
    		cnt++; 
    	}
    } 
    cout << cnt; 
 
    /// count(firstIterator, lastIterator, x) 
    int cnt = count(arr, arr+n, 1);
    int cnt = count(vec.begin(), vec.end(), 1); 
 
 
    // arr[] -> {1, 2, 5, 1, 2, 4, 4} 
    // i want you to find the first occurrence of 2
    // it is in the index 1 
 
    int ind = -1; 
    for(int i = 0;i<n;i++) {
    	if(arr[i] == x) {
    		ind = i;
    		break;
    	}
    }
    cout << ind;
 
 
    // arr[] -> {1, 2, 5, 1, 2, 4, 4} 
    auto it = find(arr, arr+n, 2); // return an iterator 
    // pointing to the first instance of it, or else it 
    // returns pointing to the end() if it is not there 
 
    int ind = it - arr; 
 
 
    auto it = find(vec.begin(), vec.end(), 2); 
    int ind = it - vec.begin(); 
 
 
    // arr[] -> {1, 5, 6, 2, 3, 5, 6}
    // x = 4 
    auto it = find(vec.begin(), vec.end(), 4); 
    if(it == vec.end()) {
    	cout << "element is not present"; 
    }
    else {
    	cout << "Element is first present at: " << it - vec.begin(); 
    }
 
 
    // binary search 
    // this stl only works on SORTED arrrays
    // arr[] -> {1, 5, 7, 9, 10} 
    // x = 9
    // true -> 9 exists in my arr 
    // x = 8 
    // false -> 8 does not exist in my arr 
 
 
    // binary_search(firstIterator, lastIterator, x)
    // returns a true or returns a false 
    // works in log n complexity 
    bool res = binary_search(arr, arr+n, 8); 
    bool res = binary_search(vec.begin(), vec.end(), 8); 
 
 
 
    // lower_bound function 
    // returns an iterator pointing to the first
    // element which is not less than x 
    // arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12} 
    // x = 10 
    // x = 6 
    // x = 13 
    // this works in log N 
 
    auto it = lower_bound(arr, arr+n, x); 
    ind = it - arr; 
 
    auto it = lower_bound(vec.begin(), vec.end(), x); 
    int ind = it - vec.begin();
 
    int ind =  lower_bound(vec.begin(), vec.end(), x) - vec.begin(); 
 
 
 
    // upper bound 
    // returns an iterator which points to an element which is 
    // just greater than x
    // arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12} 
    // x = 7 
    // x = 6 
    // x = 12 -> end() iterator 
    // x = 15 -> end() iterator 
 
    auto it = upper_bound(arr, arr+n, x); 
    ind = it - arr; 
 
    auto it = upper_bound(vec.begin(), vec.end(), x); 
    int ind = it - vec.begin();
 
    int ind =  upper_bound(vec.begin(), vec.end(), x) - vec.begin();
 
 
 
    // Q1. find me the first index where the element X lies 
    // find function can be used but that takes O(N) times
    // the array is sorted.. 
 
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++) {
    	cin >> arr[i]; 
    }
 
    int x; 
    cin >> x; 
 
    // arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12} 
    // find x = 7
    int ind = lower_bound(arr, arr+n, x) - arr; 
 
    // find x = 6 
    int ind = lower_bound(arr, arr+n, x) - arr;
 
 
 
    // There are couple of ways to do it
    // 1st way 
    if(binary_search(arr, arr+n, x) == true) {
    	cout << lower_bound(arr, arr+n, x) - arr; 
    }
    else cout << "does not exists"; 
 
 
    // 2nd way 
    int ind = lower_bound(arr, arr+n, x) - arr; 
    // arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12} 
    /////////////0  1  2  3  4  5   6   7   8   9   10 
    // find x = 13 -> ind = 11, which is out of bound 
    // hence arr[11] will give you runtime error 
    if(ind != n && arr[ind] == x) {
    	cout << "Found at: " << ind;  
    }
    else {
    	cout << "Not found";
    }
 
 
 
    // Find me the last occurrence of x in an arr 
    // arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12} 
    ///index/////0  1  2  3  4  5   6   7   8   9   10 
 
    // last occurrence of x = 10, ans = 7th index
    // last occurrence of x = 6, ans = does not exists
    // last occurrence of x = 0, 
    // last occurence of x = 13 
    int ind = upper_bound(arr, arr+n, x) - arr; 
    ind -= 1; 
    if(ind>=0 && arr[ind] == x) {
    	cout << "last occurrence: " << ind; 
    }
    else {
    	cout << "Does not exists"; 
    }
 
 
 
 
    // Q3. tell me the number of times the x appears in arr 
    // arr[] -> {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12} 
    ///index/////0  1  2  3  4  5   6   7   8   9   10 
 
    // x = 10, ans = 3 
    // x = 7, ans = 2 
 
 
    // Next Permutation 
    // string s = "abc"
    // all permutations are as follows: 
 
    // abc
    // acb 
    // bac
    // bca
    // cab
    // cba
 
 
 
    // s = "bca" 
    bool res = next_permutation(s.begin(), s.end()); 
 
    // s = "cba"
    bool res = next_permutation(s.begin(), s.end()); 
 
    // if I give you any random string s = "bca"
    // i want you to print all the permutations 
 
    string s = "bca"; 
    sort(s.begin(), s.end()); // this makes the string as "abc"
    do {
    	cout << s << endl; 
    } while(next_permutation(s.begin(), s.end())); 
 
 
    int arr[] = {1, 6, 5}; 
    int n = 3; 
    sort(arr, arr + n); // this makes the array as {1, 5, 6}
    do {
    	for(int i = 0;i<n;i++) cout << arr[i] << " "; 
    	cout << endl; 
    } while(next_permutation(arr, arr+n)) ; 
 
 
    // prev permutation 
    bool res = prev_permutation(s.begin(), s.end()); 
 
 
    // COMPARATOR 
    sort(arr, arr+n); // sorts everything in ascending order
    sort(arr, arr+n, comp); 
 
 
    // descending 
    sort(arr, arr+n, comp); 
    // greater<int> is an inbuilt comparator
    // which works only if you wanna do this in descending 
    sort(arr, arr+n, greater<int>); 
 
 
 
    // question of pair 
    sort(arr, arr+n, greater<pair<int,int>>);
 
 
    vector<vector<int>> vec(n, vectorM<int>(n, 0)); 
}
```
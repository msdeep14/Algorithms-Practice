/*
 Given a long integer return the smallest(magnitude) integer permutation of that number. The question was simple.

It could be solved by storing the number digitwise into an array and then sorting it. If the first digit is zero swap it with first non-zero digit.
*/

// CPP program to find smallest 
// permutation of given number
#include <bits/stdc++.h>
using namespace std;

// return the smallest number permutation
string findSmallestPermutation(string s){
	int len = s.length();

	// sort the string
	sort(s.begin(),s.end());

	// check for leading zero in string
	// if there are any leading zeroes, 
	// swap the first zero with first non-zero number
	int i = 0;

	while(s[i] == '0'){
		i++;
	}
	swap(s[0], s[i]);
	return s;
}

// driver program
int main(){

	// take number input in string
	string s = "5468001";
	string res = findSmallestPermutation(s);
	cout << res << endl;
	return 0;
}
/*
Given two strings return the value of least number of manipulations needed to ensure both strings have identical characters.
 For input aab aba it’s 0, for input abc cdd it is 2


*/

// CPP program to count least number
// of manipulations to have two strings
// set of same characters
#include <bits/stdc++.h>
using namespace std;

// return the count of manipulations
// required
int leastCount(string s1, string s2, int n){
	int count1[26] = {0};
	int count2[26] = {0};

	// count the number of different 
	// characters in both strings
	for(int i = 0; i < n; i++){
		count1[s1[i] - 'a'] += 1;
		count2[s2[i] - 'a'] += 1;
	}

	// check the difference of character
	// by comparing count arrays
	int res = 0;
	for(int i = 0; i < 26; i++){
		if(count1[i] != 0){
			res += abs(count1[i] - count2[i]);
		}
	}
	return res;
}

// driver program
int main(){
	string s1 = "cdd";
	string s2 = "abc";
	int len = s1.length();
	int res = leastCount(s1,s2,len);
	cout << res << endl;
	return 0;
}
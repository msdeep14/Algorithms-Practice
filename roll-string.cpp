/*
You are given a string s,an array roll where roll[i] represents rolling first roll[i] characters in string.
you have to apply every roll[i] on string and output final string.rolling means increasing ASCII value of character. like rolling ‘z’ would result in ‘a’,rolling ‘b’ would result in ‘c’,etc.
constraints: 1<=|s|<=10^5
1<=roll[i]<=10^5

For eg: Input:
bca
3
1 2 3
Output:
eeb


*/

// CPP program to find final
// string after roll operations
#include <bits/stdc++.h>
using namespace std;

// return the final string
// after performing roll operation
// on characters of string
string findRollOut(string s, int arr[], int n){
	// calculate the partial sum first
	/*
		partial sum method
		if A[] = {1,2,3}
		and you have to add a number k to a interval from 
		i to j for large no. of queries q

		The best way to do this is
		create a array B[] = {0,0,0} of same size as A[]

		now for every query from 0 to q (given three integers i, j, k)
		B[i] += k
		B[j+1] -=k
		
		run a loop for B[]
		B[i] += B[i-1]

		The final values of array A[] is
		A[i] = A[i] + B[i]  
	*/
	int brr[n+1] = {0};
	for(int i = 0; i < n; i++){
		brr[0] += 1;
		brr[arr[i]] -= 1;
	}
	for(int i = 1; i < n; i++){
		brr[i] += brr[i-1];
	}

	// change the string according to number
	// of roll operations in brr array

	// s[i] to rolled brr[i] times
	char ch[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for(int i = 0; i < n; i++){
		int x = brr[i] % 26;
		int y = s[i] - 97;
		s[i] = ch[(x+y)%26];
	}
	return s;
}

// driver program
int main(){
	string s = "zcza";
	int n = 4;

	// roll array
	int roll[] = {1,1,3,4};
	string res = findRollOut(s, roll, n);
	cout << res << endl;
	return 0;
}
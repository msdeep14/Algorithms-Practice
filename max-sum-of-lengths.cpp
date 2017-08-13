/*
Find the maximum sum of lengths of non-overlapping contiguous subarrays with k as the maximum element.
Examples:
<pre> 
arr = {2,1,4,9,2,3,8,3,4} and k = 4
Ans = 5
{2,1,4} => Length = 3
{3,4} => Length = 2
So, 3 + 2 = 5 is the answer
<pre>

<pre>
arr = {1,2,3,2,3,4,1} and k = 4
Ans = 7
{1,2,3,2,3,4,1} => Length = 7
</pre>

<pre>
arr = {4,5,7,1,2,9,8,4,3,1}
Ans = 4
{4} => Length = 1
{4,3,1} => Length = 3
So, 1 + 3 = 4 is the answer
</pre>

<strong>question source :</strong> <a target = "_blank" href = "http://www.geeksforgeeks.org/amazon-interview-experience-set-376-campus-internship/">http://www.geeksforgeeks.org/amazon-interview-experience-set-376-campus-internship/</a>

<strong>Algorithm :</strong>
<pre>
Traverse the array starting from first element
   take a loop and keep on incrementing count if element <= k
      if array element is equal to k, then mark a flag

   if flag is marked, add this count to answer

   take another loop and traverse the array till element > k

return ans
</pre>


<strong>Time Complexity :</strong> O(n)
It may look like O(n2), but if you take a closer look, array is traversed only once
*/

// CPP program to calculate max sum lengths of 
// non overlapping contiguous subarrays with k as
// max element
#include <bits/stdc++.h>
using namespace std;

// utility function which returns max sum of lengths
int calculateMaxSumLength(int arr[], int n, int k){
	int ans = 0;      // final sum of lengths
	int count = 0;   // number of elements in current subarray
	int flag = 0;   // variable for checking if k appeared in subarray
	for(int i = 0; i < n; ){
		count = 0;
		flag = 0;

		// count the number of elements which are 
		// less than equal to k
		while(arr[i] <= k && i < n){
			count += 1;
			cout << arr[i] << " ";
			if(arr[i] == k) flag = 1;
			i++;
		}
		cout << endl;
		// if current element appeared in current subarray
		// add count to sumLength
		if(flag == 1){
			ans += count;
		}

		// skip the array elements which are greater than k
		while(arr[i] > k && i < n){
			i++;
		}
	}
	return ans;
}

// driver program
int main(){
	int arr[] = {4,5,7,1,2,9,8,4,3,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	int k = 4;
	int ans = calculateMaxSumLength(arr, size, k);
	cout << "Max Length :: " << ans << endl;
	return 0;
}
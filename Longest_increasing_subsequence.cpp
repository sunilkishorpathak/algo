/*
** LIS : Longest increasing subsequence 
** Given a sequence of numbers; you have to find the longest subsequence of increasing number.
** i.e. LIS = {x1, x2, x3 .. } such that {xi < xj} where i < j
**
** 
** NOTE: There is NlogN algorithm, at this time I am going to write N*N algorithm.
**
** Create a list L of the same size as of sequence. For each i (index in subsequence),
** for each J from 0 to i-1, if A[j] A[i]
*/

#include <iostream>
using namespace std;

int LIS(int arr[], int n)
{
	int *lis = new int[n];
	//initialize the lis with 1
	for (int i=0; i < n; ++i)
		lis[i] = 1;

	//start computing the longest subsequence
	for(int i = 1; i < n; ++i) {
		for (int j=0; j < i; ++j) {
			if ( (arr[j] < arr[i]) && (lis[i] <= lis[j])) {
				lis[i] = lis[j] + 1;
			}
		}
	}

	int maxsublen = 0;
	//get the max from the lis
	for (int i=0; i < n; ++i)
		if (maxsublen < lis[i])
			maxsublen = lis[i];
	
	return maxsublen;
}

int main()
{
	int arr[] = {5, 3, 9, 4, 7, 8, 11};

	cout <<LIS(arr, sizeof(arr)/sizeof(int)) <<endl;

	return 0;
}
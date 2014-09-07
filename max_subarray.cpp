/*
**	MAX SUBARRAY : Given an array of real numbers. You have to find the subarray/contiguous subarray 
**				which has max sum.
**
** Algo: As we have to select contiguous sub-array/sequence. So if we start from the start, and think
**		about the current element, if we select the current element and that makes sum greater we will,
**		select it otherwise we will be stuck with the earlier subarray. If at any time, sum becomes -ve,
**		it mean we don't need that.
*/

#include <iostream>
using namespace std;

int MaxSubsequence(int arr[], int start, int last)
{
	int maxsum=0, thissum=0;

	for (int i=start; i <= last; ++i) {
		thissum = thissum + arr[i];

		if (thissum > maxsum)
			maxsum = thissum;

		if (thissum < 0)
			thissum = 0;
	}

	return maxsum;
}

int main()
{
	int arr[] = {4, -5, 7, -1, 8, 3};

	int maxsum = MaxSubsequence(arr, 0, 5);

	cout <<"Max sum is " <<maxsum <<endl;

	return 0;
}
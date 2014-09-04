/*
** Problem : Given an unsorted array. You have to trim the array in such a way that double of
**			max. Your trimming must be as minimum as possible. You can trim only from any ends.
**
**			e.g. arr[] = { 20, 5, 4, 9, 90, 19} -->  3 (90, 19, 20)
**
**
**	Find min and max in O(n) time. If 2*min > max return, if not
**		try to trim from both end and do the first step again.
**
**	Following is the recursive formula
**		if (2*min > max) return;
**		else
**			call the same function with [i+1 ... j]+1 and [i ... j-1]+1 and select minimum of these.
**
**  NOTE: Here we can see the same value is calculated many time
*/

//recursive solution
#include <iostream>
using namespace std;

//a utility function to find minimum of two
int min(int a, int b) { return a < b? a : b;}

//utility function to find minimum from an array
int min(int arr[], int i, int j)
{
	int minValue=0;
	for (minValue=arr[i]; i < j; ++i)
		if (minValue > arr[i])
			minValue = arr[i];
	return minValue;
}

//utility function to find maximum from an array
int max(int arr[], int i, int j)
{
	int maxValue=0;
	for (maxValue=arr[i]; i < j; ++i)
		if (maxValue < arr[i])
			maxValue = arr[i];
	return maxValue;
}

//recursive function to find the minimum number of trimming
int minTrim(int arr[], int lo, int hi)
{
	if (lo > hi) return 0;

	int minimum = min(arr, lo, hi);
	int maximum = max(arr, lo, hi);

	if (2*minimum > maximum) return 0;

	return min((minTrim(arr, lo+1, hi)+1) /* first element trimmed */, (minTrim(arr, lo, hi-1)+1) /*last element trimmed*/);
}

//Driver programm
int main()
{
	int arr[] = {20, 5, 4, 9, 90, 19};

	int trimcount = minTrim(arr, 0, 5);

	cout <<"Trim count for arr is " <<trimcount <<endl;

	return 0;
}
/*
** LAS (Longest Alternate Sequence) : Given a sequence of numbers. You have to find out the longest subsequence which is alternate. Alternate mean
**	number is more than previous and also more than next number e.g. x1 < x2 > x3 < x4 > x5 etc.
**
**
**	Algorithm : If there is 1 number, answers will be 1, if there is two number so in all cases whether x1 < x2 or x1 > x2, answers will be two.
**				Problem arises when number is three or more e.g. 1, 2, 3 max LAS will be 2 only whether we select any combination of these
**				1, 2 or 1, 3 or 2, 3 all are going up (+ve). But 1, 2, 0 has length 3 (1 to 2 +ve and 2 to 0 -ve).
**
**				So if we consider about a nubmer whose index is 3 or more. Whether ith element will be part of LAS. ith element will be part of
**				LAS only if arr[i-2] > arr[i-1] and arr[i-1] < arr[i]  OR arr[i-2] < arr[i-1] and arr[i-1] > arr[i]
**
**				As we can see the ith element will be part of LAS or not depends upon previous two values only. 
**
**	WHY DP:		At any moment LAS(i) will be optimal only if previous subproblem is optimal. So use DP. As solution depends upton only last two,
**				there is no need of any memoization.
**
**
**	RECURSIVE SOLUTION for i = 1 to n LAS(i) = { if n == 1; return 1; 
**												 if n == 2; return 2;
**												 if n >= 3; las_length = las_length + 1 
**															if [((arr[i-2] > arr[i-1]) && (arr[i-1] < arr[i]))  
**																	OR 
**															((arr[i-2] < arr[i-1]) && (arr[i-1] > arr[i]))]
*/


#include <iostream>
using namespace std;

int LAS(int arr[], int n)
{
	if ( n == 1 || n ==2 ) return n;

	int las_length = 2;

	for (int i=2; i < n; ++i) {
		if (((arr[i-2] > arr[i-1]) && (arr[i-1] < arr[i])) || ((arr[i-2] < arr[i-1]) && (arr[i-1] > arr[i])))
			las_length = las_length + 1;
	}
	return las_length;
}

int main()
{
	int arr[] = {4, 3, 7, 8, 6, 9};
	

	int length = LAS(arr, sizeof(arr)/sizeof(int));

	cout <<"length of LAS = " <<length <<endl;

	return 0;
}
		
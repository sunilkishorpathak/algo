/*
** Knapsack problem: There are some weights having some values. Say weights are w1 ... wn and there values
** from v1 ... vn. you have a knapsack/leather bag which can contain weiths upto a value C (capacity). Now
** question is you have to pick weights in such a way value can be maximized.
**
**
**	Solution: Suppose index of wiegths and their values are i ... j, we can either pick ith element or
**			leave it. If we pick it, we will consume Wi and will get value Vi. And remaining weiths will
**			be C-Wi. Now we have to pick weights for capacity C-Wi and elements from i+1 ... j
**
**			So we can see the problem has been minimized and also overlapping. So "Dynamic Programming"
**			can be used here.
**
**			Following are recursive and dynamic programming solution.
*/

#include <iostream>
using namespace std;

int W[] = {2, 5, 1, 9, 3, 4};
int V[] = {5, 1, 7, 3, 9, 4};
int n = 6; //6-1, arrays starts from 0, i.e. elements are 0 ... 5

/* Recursive solution */
int RecursiveKS(int C, int i)
{
	if ( i > n) return 0; //only there are n elements

	if (C < W[i]) //current element can not fit in the given size, skip this element and go 
		RecursiveKS(C, i+1);

	return max(RecursiveKS(C, i+1), V[i] + RecursiveKS(C-W[i], i+1));
}


#define DP 0
#if DP
/*
** Dynamic Programming solution : As many of the recursive can be stored and their 
**		computation can be avoided using MEMOIZATION 
**
**	No of colums will be  1(for 0) + max weight
**	No of rows will be 1 (for 0) + no of elements
*/

//table for memoization
int **kstable;
//C total capacity of knapsack; n total number of elements
int DynamicKS(int C, int n)
{
	if (n == 0 || C == 0 ) return 0;

	//first row which indicates there is no item, so whatever 
	for (int r=1; r <= n; ++r) {
		for (int j=1; j <= C; ++j) {
			if (W[r-1] <= j) { //this item can fit in
				if ((V[r-1] + (j-W[r] >= 0 ? kstable[r-1][j-W[r]] : 0)) > kstable[r-1][j])
					kstable[r][j] = V[r-1] + (j-W[j-1] >= 0 ? kstable[r-1][j-W[j-1]] : 0);
				else
					kstable[r][j] = kstable[r-1][j] ;
			}
			else
				kstable[r][j] = kstable[r-1][j] ;
		}
	}
	return kstable[n][C];
}

//return the maximum value in an array
int maxNumber(int V[], int n)
{
	int maxv = 0;
	for (int i=0; i <= n; i++)
		if (maxv < V[i])
			maxv = V[i];
	return maxv;
}
#endif //#dp 

int main()
{
	//Recusive call test
	cout <<RecursiveKS(10, 0) <<endl;

#if DP
	//Dynamic programming used
	//initialized table

	int i=0;
	int maxValueElement = maxNumber(V, n+1); //row
	for (i; i <= n; ++i)
		kstable = new int*[maxValueElement];
	int maxWeight = maxNumber(W, n);
	for (i=0; i <= n; ++i)
		kstable[i] = new int[maxWeight];
	//initialized to 0
	for (i = 0; i <= n; ++i)
		for (int j=0; j <= n; ++j)
			kstable[i][j] = 0;

	int knapsack_maxvalue = DynamicKS(10, 6);
	cout <<"total value in knapsack is : " <<knapsack_maxvalue <<endl;
#endif //#if DP
	return 0;
}
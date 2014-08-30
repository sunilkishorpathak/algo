/*
**	LCS : Longest common substring
**
**	Given two strings you have to find the logest common substring with/without escaping some character.
**	e.g X={A, B, C, B, D, A, B} & Y={B, D, C, A, B, A} ==> LCS={B, C, B, A} OR {B, D, A, B} ref : CLRS
**
**	c[i,j]	= 0							if i == 0 or j ==0
**			= c[i-1], j-1] + 1			if i, j > 0 & Xi == Yj
**			= min(c[i, j-1], c[i-1, j])	if i, j > 0 and Xi != Yj
**
**	Technique used: Dynamic programming becuase problem is overlapping at any time i,j we depend upon previous result
**					Memoization : Creating a table and storing result of previous
*/
//Question : Write a functio which takes two i/p string and give LCS of those

#include <iostream>
#include <string>
using namespace std;

int LCS(string& first, string& second, string& lcs)
{
	//create a two dimention matrix
	int **lcsmatrix = new int*[first.size()+1]; //1 for 
	size_t i = 0;

	for (i=0; i <=first.size(); ++i)
		lcsmatrix[i] = new int[second.size()];

	//initialize 0th row and colum with 0
	for (i=0; i <= second.size(); ++i)
		lcsmatrix[0][i] = 0;
	for(i=0; i <= first.size(); ++i)
		lcsmatrix[i][0] = 0;

	//use the above matrix and calculate 
	for (i=1; i <= first.size(); ++i) {
		for (size_t j=1; j <= second.size(); ++j) {
			if(first.at(i-1) == second.at(j-1))
				lcsmatrix[i][j] = lcsmatrix[i-1][j-1] + 1;
			else
				lcsmatrix[i][j] = (lcsmatrix[i][j-1] > lcsmatrix[i-1][j] ? lcsmatrix[i][j-1] : lcsmatrix[i-1][j]);
		}
	}
	return lcsmatrix[first.size()][second.size()];
}

int main()
{
	string X("ABCBDAB");
	string Y("BDCABA");

	string lcs;
	

	cout <<LCS(X, Y, lcs) <<endl;

	return 0;
}

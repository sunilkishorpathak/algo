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
**
**	printing subsequence path : store 'u', 'l' and 'b' to track the path. 
*/
//Question : Write a functio which takes two i/p string and give LCS of those

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LCS(string& first, string& second, string& lcs)
{
	//create a two dimention matrix
	int **lcsmatrix = new int*[first.size()+1]; //1 for 
	char **bmatrix = new char*[first.size()+1];
	size_t i = 0;

	for (i=0; i <=first.size(); ++i) {
		lcsmatrix[i] = new int[second.size()];
	
		//path matrix
		bmatrix[i] = new char[second.size()];
	}

	//initialize 0th row and colum with 0
	for (i=0; i <= second.size(); ++i)
		lcsmatrix[0][i] = 0;
	for(i=0; i <= first.size(); ++i)
		lcsmatrix[i][0] = 0;

	//use the above matrix and calculate 
	//Path: l --> left, b -->lu, u-->up
	for (i=1; i <= first.size(); ++i) {
		for (size_t j=1; j <= second.size(); ++j) {
			if(first.at(i-1) == second.at(j-1)) {
				lcsmatrix[i][j] = lcsmatrix[i-1][j-1] + 1;
				bmatrix[i][j] = 'b';
			}
			else {
				if (lcsmatrix[i][j-1] > lcsmatrix[i-1][j]) {
					lcsmatrix[i][j] = lcsmatrix[i][j-1];
					bmatrix[i][j] = 'l';
				} else {
					lcsmatrix[i][j] = lcsmatrix[i-1][j];
					bmatrix[i][j] = 'u';
				}
			}
		}
	}

	//based on l, u, b construct the path
	//start from the right bottom and go back
	i = first.size();
	size_t j = second.size();
	vector<char> path;

	while ( (i>0) && (j>0) ) {
		if ( bmatrix[i][j] == 'b') {
			path.push_back(first.at(i-1));
			i = i - 1;
			j = j - 1;
		} else {
			if( bmatrix[i][j] == 'l')
				j = j - 1;
			else
				i = i - 1;
		}
	}
	
	reverse(path.begin(), path.end());
	for (vector<char>::iterator it=path.begin(); it != path.end(); ++it)
		cout <<*it <<" ";
	cout <<endl;

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

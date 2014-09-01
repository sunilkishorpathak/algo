/*
**	LCS : Longest common substring
**
**	Given a string you have to find the logest palindrome with/without escaping some character.
**	e.g X="ABCBXA" has palindrome -->ABCBA length = 5 ; here X has been escaped
**  For more detail about the problem : http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/
**
**	Algo : If you have solved the LCS (longest common substring) problem : You can easily do this. To find out palindrome,
**			just create another string revers of the first and use LCS. As like priting the path in LCS, print that. that
**			that will be palindrome.
**
**		For your reference I have updated the LCS algo which was printing the LCS
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
**	LCS_Palindrome : Method to find the longest palindrome
**	i/p : str : string whose palindrome has to find out
**	o/p : pstring : palindrome string
**
*/


string LCS_Palindrome(string& str)
{
	//create temporary string which will have rever of the str
	string rstr(str);
	std::reverse(rstr.begin(), rstr.end());

	//create a two dimention matrix
	int **lcsmatrix = new int*[str.size()+1]; //1 for 
	
	char **bmatrix = new char*[str.size()+1];
	size_t i = 0;

	for (i=0; i <=str.size(); ++i) {
		lcsmatrix[i] = new int[rstr.size()];
	
		//path matrix
		bmatrix[i] = new char[rstr.size()];
	}

	//initialize 0th row and colum with 0
	for (i=0; i <= rstr.size(); ++i)
		lcsmatrix[0][i] = 0;
	for(i=0; i <= str.size(); ++i)
		lcsmatrix[i][0] = 0;

	//use the above matrix and calculate 
	//Path: l --> left, b -->lu, u-->up
	for (i=1; i <= str.size(); ++i) {
		for (size_t j=1; j <= rstr.size(); ++j) {
			if(str.at(i-1) == rstr.at(j-1)) {
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
	i = str.size();
	size_t j = rstr.size();
	string palindrome;

	while ( (i>0) && (j>0) ) {
		if ( bmatrix[i][j] == 'b') {
			palindrome += str.at(i-1);
			i = i - 1;
			j = j - 1;
		} else {
			if( bmatrix[i][j] == 'l')
				j = j - 1;
			else
				i = i - 1;
		}
	}
	
	return palindrome;
}

int main()
{
	string X("BBABCBCAB");

	cout <<LCS_Palindrome(X) <<endl;

	return 0;
}

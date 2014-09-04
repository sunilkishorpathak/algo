/*
** Optimal strategy for game: There ar even numbers of coins (may or may not be different). You are playing a game
**		with your opponent. You or opponent can pic the coin only from an end (start or last but not from between 
**		start and last). You have to find out how much maximum you can win if you start the game i.e. you are the
**		person who will take the first move.
**
**	Solution: This is different problem that the problem in which coins are in a row and you have to win if you
**			take the first move. In that problem we were just summing the odd and even position coins and based
**			on that sum, we were deciding we have to start from even position or odd position.
**
**		Here problem is more complex. We have to find out the the maximum value which user can collect if user takes
**		first move.
**
**		CONSIDERATION: Suppose Vi, Vi+1, Vi+2, Vi+3 .............. Vj-4, Vj-3, Vj-2, Vj-1, Vj are coins at position
**						from i to j.
**
**		Strategy/Observation:
**			User has option for picking Vi or Vj,
**			if user picks Vi, sequence will be Vi+1 ----- Vj. Opponent has option of picking Vi+1 or Vj. Opponent
**			will pick in such a way that you get coin of minimum value. i.e. after opponent what user will get
**			at least is Minimum of (Vi+2 ...... Vj) (if opponent picks Vi+1) and (Vi+1 ... Vj-1) if opponent picks Vj
**			i.e. user will get atleast [Vi + min{(Vj+2 ... Vj), (Vi+1 ... Vj-1)
**
**			Following the same, if user picks Vj, he will get minimum of {(Vi+1 .. Vj-1) <-- Opponent has picked Vi
**																		and (Vi .. Vj-2) <-- Opponent has picked Vj-1
**
**		As we have to maximize our value, we will surely try to get the maximum of above two.
**
**			One more thing we can notice is, we are calculating the same problem but smaller one e.g instead of
**			calculating (Vi .... Vj) we are calculating (Vi+1 ... Vj-1) in both the cases. Storing this result in
**			some table can help to avoid recalculating.
**
**			The other observation : If we see our problem get smaller and for the smaller problem we are getting the max
**			. Storing the max helps us to maximize our value for bitter. I.e. sub-optimal solution is here.
**
**	As there is overlapping problem and suboptimal solution, this problem come in "DYNAMIC PROGRAMMING"	category.
**
**		Think about the memoization and store calculated value in table. 
**
**	Ref : http://www.geeksforgeeks.org/dynamic-programming-set-31-optimal-strategy-for-a-game/
**
**	Please also go through the link : http://tech-queries.blogspot.in/2011/06/get-maximum-sum-from-coins-in-line.html
**			
*/

#include <iostream>
#include <vector>
using namespace std;

int **maxmatrix; //Golobal variable to store the value

int MaxCoinValue(vector<int>& row)
{
	/*
	** For each gap from 0 to n; fill the matrix
	*/
	int x, y, z;
	int n = row.size();

	for (int gap=0; gap < n; ++gap) {
		for (int i=0, j=gap; j < n; ++i, ++j) {
			x = ((i+2) <= j) ? maxmatrix[i+2][j] : 0;
			y = ((i+1) <= (j-1)) ? maxmatrix[i+1][j-1] : 0; 
			z = (i <= (j-2)) ? maxmatrix[i][j-2] : 0;

			maxmatrix[i][j] = max((row[i] + min(x, y)), (row[j] + min(y,z)));
		}
	}

	return maxmatrix[0][n-1]; //this contains the max value which can be stored
}

int main()
{
	//allocate memory to the valuematrix and initialize it with zero.
	vector<int> row;
	row.push_back(18);
	row.push_back(15);
	row.push_back(11);
	row.push_back(27);

	int size = row.size();
	
	maxmatrix = new int*[size];
	for (int i=0; i < size; ++i)
		maxmatrix[i] = new int[size];

	int userMaxValue = MaxCoinValue(row);

	cout <<"Max value user can get is : " <<userMaxValue <<endl;

	return 0;
}
	
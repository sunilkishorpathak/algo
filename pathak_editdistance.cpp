/*
** Edit distance
** In this problem we have to find out how many actions are required to convert one string into another.
** Operations available are "add", "delete" or "replace"
** e.g. sunny to bunny --> one operation replace is required to convert s to b
**
** Looking into the problem it's clear that to decide about the nth character, if we have solution for
** upto n-1, we have to add only 1 operation. i.e. problem is overlaping and have property of sub-optimal
** solution. So we will use DYNAMIC PROPERTY.
**
** We will use memoization to solve this problem.
** Taking one example let's we have to convert sunny --> bunny
**
**  Let's we have "" (empty string) and we need to convert to bunny, following table will give you the operations
** --------------------------
**      ""	 b	u	n	n	y
**	""	0	1	2	3	4	5	<-- Distance of converting "" to "", "b", "bu", "bun", "bunn", "bunny"
**
** Now we have one character "s". Now we have to calculate distance for "", "b", "bu", "bun", ....
** For converting s to "" simple one operation is required "delete" "s".
"" What about converting "s" to "b"
**	option 1. "add" (i.e. add "t" resluting "sb") + 1 operation to convert "s" to "" (empty string) we can get it from looking left
**	option 2. "delete" (i.e. delete s resulting "") + 1 operation to convert "" to "b" (we can get it by looking up)
**	option 3. "replace" (i.e. replace "s" by "b") + 1 operation to convert "" to "" (we can take it by diagonal back)
**
** So at any time, cost will be like
**	total cost = min [ EDC(j-1, i) | EDC(j, i-1) | EDC(j-1, i-1) + cost of cost (if chars are same it will be otherwise replacement cost 1]
*/


#include <iostream>
#include <string>
using namespace std;

int MinimumOf3(int first, int second, int third)
{
	if (first < second)
		return first < third ? first : third;
	else
		return second < third ? second : third;
}

int EditDistanceCost(const string& sFrom, const string& sTo)
{
	int edc = 0;

	//create a matrix of sizeof(sFrom)+1, sizeof(sTo)+1
	int **edcmatrix = new int*[sFrom.size()+1];	
	//row for pointers have been created; go and allocate memory for each
	size_t i=0, j=0;
	for ( i=0; i < sFrom.size()+1; ++i)
		edcmatrix[i] = new int[sTo.size()+1];

	//as frist row has been converted from " " to the element; initialize it with 0 to sTo.size()
	for ( i=0; i < sTo.size()+1; ++i) 
		edcmatrix[0][i] = i;
	//also initialized first element to sFrom as 0 to sFrom.size()+1
	for (i = 0; i < sFrom.size()+1; ++i)
		edcmatrix[i][0] = i;

	//now follow the  equation
	i=0, j=0;
	for ( i = 1; i <= sFrom.size(); ++i) {
		for ( j=1; j <=sTo.size(); ++j) {
			//int x = 0;
			//x = sFrom.at(i-1) != sTo.at(j-1) ? 1 : 0;
			edcmatrix[i][j] = MinimumOf3(edcmatrix[i][j-1], edcmatrix[i-1][j], edcmatrix[i-1][j-1]) + (sFrom.at(i-1) != sTo.at(j-1) ? 1 : 0);
		}
	}

	//return the last (bottom, right) element

	return edcmatrix[sFrom.size()][sTo.size()];
}

int main()
{
	string first("abc"), second("cba");

	/*
	cout <<"Enter string for calculating the edit distance :\n";
	cout <<"First string : " ;
	cin >> first;
	cout <<"Second string : ";
	cin >> second;
	*/
	

	int editdistance = EditDistanceCost(first, second);

	cout <<"Edit distance is : " <<editdistance <<endl;

	return 0;
}



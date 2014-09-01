/*
** SuffixArray : An array of all suffixes
** e.g. for banana suffixes are "0:banana", "1:anana", "2:nana', "3:ana", "4:na" & "5:a"
**	integers shows the index of the suffix
**
** Algo create a pair of startpos & the suffix, put in a vector and sort it
**
** Searching in suffix array.
**	Algo : As array is sorted, binary search can be used to find whether the given string is present or not
**
**	I have kept this algo as easy as possible. I can calculate the index, based on the string in the vector it's
**	and the size of the actual string from which suffix array has been created. 
**	pos will be equals orginalsring.size() - (strings in vector).size()
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>	//sort
#include <utility>
using namespace std;

void CreateSuffixArray(const string& str, vector<string>& sa)
{
	//from the string according to suffix pos, create suffix
	sa.reserve(str.size());

	vector<string> vString;
	int n = str.size();

	for (int i = 0; i < str.size(); ++i)
		sa.push_back(str.substr(i, n));
	//print the unsorted strings with suffixes

	cout <<"Unsorted suffix arrays are \n";
	for (vector<string>::iterator sait = sa.begin(); sait != sa.end(); ++sait)
		cout <<sait->size() <<"\t" <<*sait <<endl;

	std::sort(sa.begin(), sa.end());
	for (vector<string>::iterator it=vString.begin(); it != vString.end(); ++it)
		cout <<*it <<endl;
}

bool SearchInSuffixarray(vector<string> sarray, string pattern)
{
	int pos = 0;
	//use binary search to find the given text in suffix array.
	int left = 0, right = sarray.size(), mid=0;

	while (left < right) {
		mid = (left + right)/2;

		int ret = sarray.at(mid).compare(0, pattern.size(), pattern);
		if (ret == 0) 
			return true;
		else {
			if ( ret > 0 ) 
				right = mid - 1;
			else
				left = mid + 1;
		}
	}

	return pos+1;
}
int main()
{
	string str("banana");

	vector<string> SuffixArray;

	CreateSuffixArray(str, SuffixArray);

	//print out all suffix array with their indexes
	cout <<"Sorted suffix arrays are\n";
	for(vector<string>::iterator it=SuffixArray.begin(); it != SuffixArray.end(); ++it)
		cout <<it->size()<<"\t" <<*it <<endl;

	cout <<"searching for a pattern nan \n";
	string pattern("nan");

	cout <<"found : " <<SearchInSuffixarray(SuffixArray, pattern) <<endl;

	return 0;
}





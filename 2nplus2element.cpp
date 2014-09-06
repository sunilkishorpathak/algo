/*
**	Problem : There is unsorted array of integers having 2n+2 numbers. Out of 2n+2 number
**			n numbers are repeated and but 2 numbers are unique i.e. and two are unique 
**			e.g. 2, 5, 3, 3, 4, 2 (2 and 3 are two time but 5 and 4 are not repeated 
**			they are unique) . You have to find the unique numbers.
** 
**	In previous questions to find the unique nubmer out of 2n+1, we did xor of all numbers
**	and got the single unique number. Here there are two unique numbers so we need to find
**	one more equation to decide the value.
**	i.e. First equation (assumming x and y are unique)
**			x^y = xyz
**
**
**	As stated both numbers are different, so at least one bit will bet in resulting number.
**	Get the bit set position and again do xor of all number which has that bit set, doing
**	so will give you the number (out of x and y) which has that bit set.
*/

#include <iostream>
using namespace std;

pair<int, int> Find2OddElement(int arr[], int start, int last)
{
	

	//do xor of all number
	int i=start;
	int xor_value = arr[start];
	for (i = start+1; i <= last; ++i) 
		xor_value = xor_value ^ arr[i];

	//find the first set bit
	int xor_value_first_set_bit = xor_value ^ (xor_value & (xor_value-1));

	//we have to xor of all the value which have set bit at xor_value_first_set_bit
	int first_number=0;
	for(i = 0; i <= last; ++i) {
		if (xor_value_first_set_bit & arr[i]) { //got the first bit number, initialize the first number
			first_number ^= arr[i];
		}
	}
	first_number ^= 0; //to eleminate the initialization with 0

	int second_number = xor_value ^ first_number;

	//return values
	pair<int, int> odd_2_number(first_number, second_number);

	//test: print both number
	cout <<"Odd Nmber are " <<first_number <<"\t" <<second_number <<endl;
	return odd_2_number;
}

//driver program
int main()
{
	int arr[] = {3, 2, 6, 5, 2, 3, 5, 7};

	Find2OddElement(arr, 0, 7);

	return 0;
}

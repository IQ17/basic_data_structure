//Subsets
//
//Given a set of distinct integers, S, return all possible subsets.
//
//Note:
//
//Elements in a subset must be in non - descending order.
//The solution set must not contain duplicate subsets.
//
//For example,
//If S = [1, 2, 3], a solution is :
//
//[
//	[3],
//	[1],
//	[2],
//	[1, 2, 3],
//	[1, 3],
//	[2, 3],
//	[1, 2],
//	[]
//]
//
//标签: Array Backtracking Bit Manipulation
//	分析
//
//	每个元素，都有两种选择，选或者不选。


#include <iostream>
using namespace std;

void subsets(bool* indicators, size_t len, size_t currentElementIndex)
{
	if (len == currentElementIndex)
	{
		for (size_t i = 0; i < len; i++)
		{
			cout << indicators[i];
		}
		cout << endl;
		return;
	}

	indicators[currentElementIndex] = false; // case1 select 
	subsets(indicators, len, currentElementIndex + 1);
	indicators[currentElementIndex] = true;  // case2 not select
	subsets(indicators, len, currentElementIndex + 1);
}

int main()
{
	size_t len = 3;
	bool* indicators = new bool[len];
	for (size_t i = 0; i < len; i++)
	{
		indicators[i] = false;
	}

	size_t currentElementIndex = 0;
	subsets(indicators, len, currentElementIndex);

	delete [] indicators;
	return 0;
}
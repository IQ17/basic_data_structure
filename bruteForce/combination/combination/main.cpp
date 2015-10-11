//Combinations
//
//Given two integers n and k, return all possible combinations of k numbers out of 1 °≠ n.
//
//For example,
//If n = 4 and k = 2, a solution is :
//
//[
//	[2, 4],
//	[3, 4],
//	[2, 3],
//	[1, 2],
//	[1, 3],
//	[1, 4],
//]
//
//±Í«©: Backtracking

#include <iostream>
using namespace std;

void combination(const size_t totalNumberOfElements, const size_t numberOfElementsToSelect, size_t startIndex, size_t numberOfSelectedElements, bool* indicator)
{
	if (numberOfElementsToSelect == numberOfSelectedElements)
	{
		cout << "[ ";
		for (size_t i = 0; i < totalNumberOfElements; i++)
		{
			if (indicator[i] == true)
			{
				cout << i << " ";
			}
		}
		cout << "]" << endl;
		return;
	}

	for (size_t i = startIndex; i < totalNumberOfElements; i++)
	{
		indicator[i] = true;
		// i+1, search afterwards
		combination(totalNumberOfElements, numberOfElementsToSelect, i + 1, numberOfSelectedElements + 1, indicator); 
		indicator[i] = false;
	}
}

int main()
{
	const size_t totalNumberOfElements = 4;
	const size_t numberOfElementsToSelect = 2;

	bool* indicator = new bool[totalNumberOfElements];
	for (size_t i = 0; i < totalNumberOfElements; i++)
	{
		indicator[i] = false;
	}

	size_t numberOfSelectedElements = 0;
	size_t startIndex = 0;
	combination(totalNumberOfElements, numberOfElementsToSelect, startIndex, numberOfSelectedElements, indicator);

	delete[] indicator;
	return 0;
}
//Permutations
//
//Given a collection of numbers, return all possible permutations.
//
//For example,
//[1, 2, 3] have the following permutations :
//[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and[3, 2, 1].
//
//±Í«© : Backtracking


#include <iostream>
using namespace std;

template<typename T>
void swap(T arr[], T& index1, T& index2)
{
	T tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}

void permuation(size_t arr[], size_t beginIndex, size_t endIndex)
{
	if (beginIndex == endIndex)
	{
		for (size_t i = 0; i <= endIndex; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	for (size_t i = beginIndex; i <= endIndex; i++)
	{
		swap<size_t>(arr, beginIndex, i);
		permuation(arr, beginIndex + 1, endIndex);
		swap<size_t>(arr, i, beginIndex);
	}
}

int main()
{
	size_t arr[] = { 1, 2, 3};
	size_t len = sizeof(arr) / sizeof(arr[0]);

	size_t beginIndex = 0;
	size_t endIndex = len - 1;
	permuation(arr, beginIndex, endIndex);

	return 0;
}
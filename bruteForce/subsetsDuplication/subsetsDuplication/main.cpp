//Subsets II
//
//Given a collection of integers that might contain duplicates, S, return all possible subsets.
//
//Note:
//
//Elements in a subset must be in non - descending order.
//The solution set must not contain duplicate subsets.
//
//For example,
//If S = [1, 2, 2], a solution is :
//
//[
//	[2],
//	[1],
//	[1, 2, 2],
//	[2, 2],
//	[1, 2],
//	[]
//]
//
//标签: Array Backtracking
//	分析
//
//	这题有重复元素，但本质上，跟上一题很类似，上一题中元素没有重复，相当于每个元素只能
//	选0 或1 次，这里扩充到了每个元素可以选0 到若干次而已。

#include <iostream>
using namespace std;

const char str[] = "ABB";

void subsetsDuplication(const size_t* histogram, size_t* selected, const size_t len, size_t currentElementIndex)
{
	if (len == currentElementIndex)
	{
		for (size_t i = 0; i < len; i++)
		{
			for (size_t j = 0; j < selected[i]; j++)
			{
				cout << str[i];
			}
		}
		cout << endl;
		return;
	}

	for (size_t i = 0; i <= histogram[currentElementIndex]; i++) // <=
	{
		selected[currentElementIndex] = i;
		subsetsDuplication(histogram, selected, len, currentElementIndex + 1);
	}
}

int main()
{

	size_t len = sizeof(str) / sizeof(str[0]) - 1;

	size_t* histogram = new size_t [len];
	size_t* selected = new size_t[len];
	for (size_t i = 0; i < len; i++)
	{
		histogram[i] = 0;
		selected[i] = 0;
	}

	for (size_t i = 0; i < len; i++)
	{
		histogram[str[i] - str[0]]++;
	}

	size_t currentElementIndex = 0;
	subsetsDuplication(histogram, selected, len, currentElementIndex);
 
	delete[] histogram;
	delete[] selected;
	return 0;
}
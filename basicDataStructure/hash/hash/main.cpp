#include <iostream>
#include "hash.h"
using namespace std;

int main()
{
	hash_table<int> h;
	for (size_t i = 0; i < 22; i++)
	{
		h.insert(i);
		h.insert(i);
	}
	h.display();

	return 0;
}
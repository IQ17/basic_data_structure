#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.display_top_down();
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}
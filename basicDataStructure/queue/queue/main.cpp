#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
	queue<int> q;
	q.display();
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.display();
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.dequeue();
	}
	return 0;
}
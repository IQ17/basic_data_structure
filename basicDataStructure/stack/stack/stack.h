#pragma once
#include <assert.h>

template<typename T>
struct node
{
	T value;
	struct node<T>*  privous_ptr;
};

template<typename T>
class stack
{

public:
	stack();
	~stack();

	void push(T val);
	void pop();
	T& top();

	void display_top_down();
	void clear();
	bool empty();

private:
	struct node<T>* m_topPtr;
	struct node<T>* m_size;
};

template<typename T>
stack<T>::stack()
{
	m_topPtr = NULL;
	m_size = 0;
}

template<typename T>
stack<T>::~stack()
{
	clear();
}

template<typename T>
void stack<T>::clear()
{
	while (m_topPtr != NULL)
	{
		struct node<T>* tmpPtr = m_topPtr;
		m_topPtr = m_topPtr->privous_ptr;
		m_size--;
		delete tmpPtr;
	}
}

template<typename T>
void stack<T>::push(T val)
{
	struct node<T>* tmpPtr = new node<T>;
	tmpPtr->value = val;
	tmpPtr->privous_ptr = m_topPtr;
	m_topPtr = tmpPtr;
	m_size++;
}

template<typename T>
void stack<T>::display_top_down()
{
	struct node<T>* tmpPtr = m_topPtr;
	while (tmpPtr != NULL)
	{
		cout << tmpPtr->value << " ";
		tmpPtr = tmpPtr->privous_ptr;
	}
	cout << endl;
}

template<typename T>
T& stack<T>::top()
{
	assert(m_topPtr != NULL);
	return m_topPtr->value;
}

template<typename T>
void stack<T>::pop()
{
	assert(m_topPtr != NULL);
	struct node<T>* tmpPtr = m_topPtr;
	m_topPtr = m_topPtr->privous_ptr;
	delete tmpPtr;
	m_size--;
}

template<typename T>
bool stack<T>::empty()
{
	return m_size <= 0;
}
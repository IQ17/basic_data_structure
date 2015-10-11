#pragma once
#include <iostream>
#include <assert.h>

template<typename T>
struct node
{
	T value;
	struct node* privous_ptr;
	struct node* next_ptr;
};

template<typename T>
class queue
{
private:
	struct node<T>* m_head_ptr;
	struct node<T>* m_rear_ptr;
	size_t m_size;

public:
	queue();
	~queue();
	void clear();
	bool empty();
	void enqueue(T val);
	T& front();
	void dequeue();
	void display();
};

template<typename T>
queue<T>::queue()
{
	m_head_ptr = NULL;
	m_rear_ptr = NULL;
	m_size = 0;
}

template<typename T>
queue<T>::~queue()
{
	clear();
}

template<typename T>
void queue<T>::clear()
{
	while (m_head_ptr != NULL)
	{
		struct node<T>* tmpPtr = m_head_ptr;
		m_head_ptr = m_head_ptr->next_ptr;
		m_size--;
		delete tmpPtr;
	}
	m_rear_ptr = NULL;
}

template<typename T>
bool queue<T>::empty()
{
	return m_size <= 0;
}

template<typename T>
void queue<T>::enqueue(T val)
{
	struct node<T>* newNodePtr = new node<T>;
	newNodePtr->privous_ptr = m_rear_ptr;
	newNodePtr->next_ptr = NULL;
	newNodePtr->value = val;
	m_rear_ptr = newNodePtr;

	if (empty())
	{
		m_head_ptr = newNodePtr;
	}
	else
	{
		m_head_ptr->next_ptr = (m_head_ptr->next_ptr == NULL) ? m_rear_ptr : m_head_ptr->next_ptr;
		m_rear_ptr->privous_ptr->next_ptr = m_rear_ptr;
	}

	m_size++;
}

template<typename T>
T& queue<T>::front()
{
	assert(m_head_ptr != NULL);
	return m_head_ptr->value;
}

template<typename T>
void queue<T>::dequeue()
{
	assert(m_head_ptr != NULL);
	struct node<T>* tmpPtr = m_head_ptr;
	m_head_ptr = m_head_ptr->next_ptr;
	delete tmpPtr;
	m_size--;
}

template<typename T>
void queue<T>::display()
{
	struct node<T>* tmpPtr = m_head_ptr;
	while (tmpPtr != NULL)
	{
		cout << tmpPtr->value << " ";
		tmpPtr = tmpPtr->next_ptr;
	}
	cout << endl;
}
#pragma once
#include <assert.h>

template<typename T>
struct element_node
{
	T value;
	struct element_node<T>* next_ptr;
};

template<typename T>
struct hash_table_node
{
	int hash_code;
	struct element_node<T>* element_ptr;
};

template<typename T>
class hash_table
{
public:
	hash_table(int hash_table_length = 11);
	~hash_table();
	void display();
	bool insert(T value);
	bool is_existing(T value);
	int get_hash_code(T value);
private:
	int m_hash_table_length;
	struct hash_table_node<T>* m_head_ptr;

};

template<typename T>
hash_table<T>::hash_table(int hash_table_length) :m_hash_table_length(hash_table_length)
{
	assert(m_hash_table_length > 0);
	m_head_ptr = new struct hash_table_node<T>[m_hash_table_length];
	for (size_t i = 0; i < m_hash_table_length; i++)
	{
		m_head_ptr[i].hash_code = i;
		m_head_ptr[i].element_ptr = NULL;
	}
}

template<typename T>
hash_table<T>::~hash_table()
{
	for (size_t i = 0; i < m_hash_table_length; i++)
	{
		while (m_head_ptr[i].element_ptr != NULL)
		{
			struct element_node<T>* tmpPtr = m_head_ptr[i].element_ptr; 
			m_head_ptr[i].element_ptr = m_head_ptr[i].element_ptr->next_ptr;
			delete tmpPtr;
		}
	}
	delete[] m_head_ptr;
}

template<typename T>
void hash_table<T>::display()
{
	for (size_t i = 0; i < m_hash_table_length; ++i)
	{
		while (m_head_ptr[i].element_ptr != NULL)
		{
			struct element_node<T>* tmpPtr = m_head_ptr[i].element_ptr;
			m_head_ptr[i].element_ptr = m_head_ptr[i].element_ptr->next_ptr;
			std::cout << tmpPtr->value << " ";
		}
		std::cout << std::endl;
	}
}

template<typename T>
bool hash_table<T>::insert(T val)
{
	if (!is_existing(val))
	{
		int hashCode = get_hash_code(val);
		
		struct element_node<T>* newElementPtr = new struct element_node<T> ;
		newElementPtr->value = val;
		newElementPtr->next_ptr = m_head_ptr[hashCode].element_ptr;

		m_head_ptr[hashCode].element_ptr = newElementPtr;
		
		return true;
	}
	return false;
}

template<typename T>
int hash_table<T>::get_hash_code(T value)
{
	return static_cast<int>(value) % m_hash_table_length;
}

template<typename T>
bool hash_table<T>::is_existing(T value)
{
	int hashCode = get_hash_code(value);
	struct element_node<T>* tmpPtr = m_head_ptr[hashCode].element_ptr;

	while (tmpPtr != NULL)
	{
		if (tmpPtr->value == value)
		{
			return true;
		}
		else
		{
			tmpPtr = tmpPtr->next_ptr;
		}
	}
	return false;
}

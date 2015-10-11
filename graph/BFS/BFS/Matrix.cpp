#include "Matrix.h"
#include <fstream>
#include <iostream>
using namespace std;

matrix::matrix(string file_name)
{
	ifstream input(file_name);
	input >> rows >> cols;

	data = new char*[rows];
	for (size_t row = 0; row < rows; row++)
	{
		data[row] = new char[cols];
		for (size_t col = 0; col < cols; col++)
		{
			input >> data[row][col];
		}
	}

	input.close();
}

matrix::~matrix()
{
	for (size_t row = 0; row < rows; row++)
	{
		delete[] data[row];
	}
	delete[] data;
}

void matrix::display()
{
	cout << endl;
	for (size_t row = 0; row < rows; row++)
	{
		for (size_t col = 0; col < cols; col++)
		{
			cout << data[row][col] << " ";
		}
		cout << endl;
	}
}

void matrix::check_boundary()
{
	check_line(0, 'r');
	check_line(rows - 1, 'r');
	check_line(0, 'c');
	check_line(cols - 1, 'c');
}

void matrix::check_line(size_t idx, char row_or_line)
{
	if (row_or_line == 'r')
	{
		for (size_t col = 0; col < cols; col++)
		{
			if (data[idx][col] == 'O')
			{
				data[idx][col] = 'F';
			}
		}
	}
	else
	{
		for (size_t row = 0; row < rows; row++)
		{
			if (data[row][idx] == 'O')
			{
				data[row][idx] = 'F';
			}
		}
	}
}

position matrix::find_element_need_check()
{
	for (size_t row = 0; row < rows; row++)
	{
		for (size_t col = 0; col < cols; col++)
		{
			if (data[row][col] == 'O')
			{
				return position(row, col);
			}
		}
	}
	return position(-1, -1);
}

void matrix::flip_surrounded_regions()
{
	while (1)
	{
		position pos = find_element_need_check();
		if (pos.r0 == -1 && pos.c0 == -1) break;



	}
}
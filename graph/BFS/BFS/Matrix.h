#pragma once
#include <string>
using namespace std;

struct position
{
	int r0;
	int c0;
	position(int r0_, int c0_) :r0(r0_), c0(c0_){}
};

class matrix
{
private:
	char** data;
	size_t rows;
	size_t cols;
private:
	void check_line(size_t idx, char row_or_line);
	position find_element_need_check();
public:
	matrix(string file_name);
	~matrix();
	void display();
	void check_boundary();
	void flip_surrounded_regions();
};


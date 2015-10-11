#include <iostream>
#include "Matrix.h"
using namespace std;




int main()
{
	matrix mat("input.txt");

	mat.check_boundary();
	mat.flip_surrounded_regions();

	
	mat.display();
	return 0;
}
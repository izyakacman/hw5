﻿/**
*	main.cpp
*/

#include <iostream>

#include "matrix.h"

using namespace std;

int main()
{
	Matrix<int, 0> matrix;

	auto a =  matrix[1][1];

	for (int i = 0; i < 10; ++i)
	{
		matrix[i][i] = i;
		matrix[i][9 - i] = 9 - i;
	}

	for (int i = 1; i < 9; ++i)
	{
		for (int j = 1; j < 9; ++j)
		{
			int n = matrix[i][j];
			cout << n << " ";
		}

		cout << endl;
	}

	cout << "Matrix size = " << matrix.Size() << endl;

	for (auto c : matrix)
	{
		cout << "[" << c.first[0] << ", " << c.first[1] << "] = " << c.second << endl;
	}

	return 0;
}

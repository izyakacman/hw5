/**
*	main.cpp: определяет точку входа для приложения.
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

	(matrix[11][11] = 0) = 111;
	matrix[0][0] = 0;

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
		cout << "[" << matrix.GetX(c.first) << ", " << matrix.GetY(c.first) << "] = " << c.second << endl;
	}

	return 0;
}

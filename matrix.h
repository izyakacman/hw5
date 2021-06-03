/**
*	Модуль работы с бесконечной матрицой
* 
*	Храним значения в ассоациативном массиве map<size_t, T>,
*	где ключ key = i*10+j, например
*	Matrix[1][2] -> map[12]
* 
*/

#pragma once

#include <iostream>
#include <map>

template<typename T>
using matrix_iterator = typename std::map<size_t, T>::iterator;

/**
*	Элемент матрицы
*/
template<typename T, T def>
class MatrixValue
{
public:

	MatrixValue() = default;
	~MatrixValue() = default;

	T& operator=(const T& other)
	{
		if (other == def)
		{
			if (m_map.find(m_index) != m_map.cend())
			{
				m_map.erase(m_index);
			}

			return m_default_lvalue;
		}

		m_map[m_index] = other;

		return m_map[m_index];
	}

	operator T()
	{
		if (m_map.find(m_index) != m_map.cend())
		{
			return m_map[m_index];
		}
		else
		{
			return def;
		}
	}

	void SetIndex(size_t index)
	{
		m_index = index;
	}

	size_t Size()
	{
		return m_map.size();
	}
	
	matrix_iterator<T> begin()
	{
		return m_map.begin();
	}

	matrix_iterator<T> end()
	{
		return m_map.end();
	}

private:

	std::map<size_t, T> m_map;
	T m_default_lvalue = def;
	size_t m_index = 0;
};

/**
*	Вспомогательная матрица
*/
template<typename T, T def>
class SubMatrix
{
public:

	SubMatrix() = default;
	~SubMatrix() = default;

	MatrixValue<T, def>& operator[](int index)
	{
		m_index = m_index * 10 + index;

		m_value.SetIndex(m_index);

		return m_value;
	}

	size_t Size()
	{
		return m_value.Size();
	}

	void SetIndex(size_t index)
	{
		m_index = index;
	}

	matrix_iterator<T> begin()
	{
		return m_value.begin();
	}

	matrix_iterator<T> end()
	{
		return m_value.end();
	}

private:

	size_t m_index = 0;
	MatrixValue<T, def> m_value;
};

/**
*	Бесконечная матрица
*/
template<typename T, T def>
class Matrix
{
public:
	Matrix() = default;
	~Matrix() = default;

	SubMatrix<T, def>& operator[](size_t index)
	{
		m_sub_matrix.SetIndex(index);

		return m_sub_matrix;
	}

	size_t Size()
	{
		return m_sub_matrix.Size();
	}

	matrix_iterator<T> begin()
	{
		return m_sub_matrix.begin();
	}

	matrix_iterator<T> end()
	{
		return m_sub_matrix.end();
	}

	static size_t GetX(size_t complex_idndex)
	{
		return complex_idndex / 10;
	}

	static size_t GetY(size_t complex_idndex)
	{
		return complex_idndex % 10;
	}

private:

	SubMatrix<T, def> m_sub_matrix;

};

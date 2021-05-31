#pragma once

#include <iostream>
#include <map>

using namespace std;

template<typename T, T def>
class MatrixMap
{
public:
	MatrixMap() = default;
	~MatrixMap() = default;

private:

};


template<typename T, T def>
class SubMatrix
{
public:

	SubMatrix() = default;
	~SubMatrix() = default;

	T& operator[](int index)
	{
		//cout << m_index << " " << index << endl;

		m_index = m_index * 10 + index;

		return m_map[m_index];
	}
/*
	const T& operator[](int index) const
	{
		m_index = m_index * 10 + index;

		if (m_map.find(m_index) == m_map.cend())
			return def;
		else
			return m_map[m_index];
	}
	*/
/*
	T& operator=(const T& other)
	{
		if (other == def)
		{
			if (m_map.find(m_index) != m_map.cend())
				m_map.erase(m_index);
		}
		else
		{
			m_map[]
		}
	}
*/
	size_t Size()
	{
		return m_map.size();
	}

	void SetIndex(int index)
	{
		m_index = index;
	}

private:

	int m_index = 0;
	int def_value = def;
	map<int, T> m_map;
};

template<typename T, T def>
class Matrix
{
public:
	Matrix() = default;
	~Matrix() = default;

	SubMatrix<T, def>& operator[](int index)
	{
		m_sub_matrix.SetIndex(index);

		return m_sub_matrix;
	}

	size_t Size()
	{
		return m_sub_matrix.Size();
	}

private:

	SubMatrix<T, def> m_sub_matrix;

};


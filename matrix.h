/**
*	Endles matrix of T type elements
* 
*	Save matrix's values in the map<vector<size_t>, T>,
*	where vector<size_t> is the matrix index 
* 
*/

#pragma once

#include <vector>
#include <map>

template<typename T>
using matrix_iterator = typename std::map<std::vector<size_t>, T>::iterator;

template<typename T>
using matrix_const_iterator = typename std::map<std::vector<size_t>, T>::const_iterator;

/**
*	Endless matrix
*/
template<typename T, T def>
class Matrix
{
public:

	Matrix() = default;
	~Matrix() = default;

	Matrix<T, def>& operator[](size_t index)
	{
		m_index_vector.push_back(index);

		return *this;
	}

	T& operator=(const T& other)
	{
		std::vector<size_t> tmp_index_vector = std::move(m_index_vector);
		m_index_vector.clear();

		if (other == def)
		{
			if (m_map.find(tmp_index_vector) != m_map.cend())
			{
				m_map.erase(tmp_index_vector);
			}

			return m_default_lvalue;
		}

		m_map[tmp_index_vector] = other;

		return m_map[tmp_index_vector];
	}

	operator T()
	{
		T res = def;

		if (m_map.find(m_index_vector) != m_map.cend())
		{
			res = m_map[m_index_vector];
		}

		m_index_vector.clear();

		return res;
	}

	size_t Size() const
	{
		return m_map.size();
	}

	matrix_iterator<T> begin()
	{
		return m_map.begin();
	}
	
	matrix_const_iterator<T> cbegin() const
	{
		return m_map.cbegin();
	}

	matrix_iterator<T> end()
	{
		return m_map.end();
	}

	matrix_const_iterator<T> cend() const
	{
		return m_map.cend();
	}

private:

	std::vector<size_t> m_index_vector;
	std::map<std::vector<size_t>, T> m_map;
	T m_default_lvalue = def;
};

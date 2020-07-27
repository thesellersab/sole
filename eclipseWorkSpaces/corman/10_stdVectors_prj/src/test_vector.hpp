/*
 * test_vector.hpp
 *
 *  Created on: Jul 19, 2020
 *      Author: shahzadb
 */

#ifndef TEST_VECTOR_HPP_
#define TEST_VECTOR_HPP_
#include <iostream>

class testVector {
public:
	int m_size;
	int *m_data;
	testVector(int p_size=1):m_size(p_size)
	{
		m_data =  new int[p_size];
	}

	void print()
	{
		std::cout<<"X = "<<m_size<<std::endl;
	}
	int & operator[] (int x)
	{
		return m_data[x];
	}
	~testVector()
	{
		delete m_data;
	}
};


#endif /* TEST_VECTOR_HPP_ */

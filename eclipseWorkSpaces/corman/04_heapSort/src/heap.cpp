/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *

                   || مصنف:موسیقار پروگرامر ||

    *     *     *     *     *     *     *     *     *
*      *     *     *     *     *     *     *     *     *


*/

/*
 * heap.cpp
 *
 *  Created on: Jun 26, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#include "heap.hpp"
#include <vector>


namespace maosikar {



Heap::Heap()
{
	m_data = new std::vector<int>(8);
	m_size = 0;
	m_capacity = 8;
}

Heap::Heap(int p_capaccity)
{
	m_data = new std::vector<int>(p_capaccity);
	m_size = 0;
	m_capacity = 8;
}
int Heap::getParentIndex(int p_childIndex)
{
	return (p_childIndex-1)/2;
}
int Heap::getLeftChildIndex(int p_parentIndex)
{
	return ((p_parentIndex+1)*2)-1;
}
int Heap::getRightChildIndex(int p_parentIndex)
{
	return ((p_parentIndex+1)*2);
}
void Heap  ::insert(int p_element)
{
	if(m_size==0)
	{
		m_data->at(0) = p_element;
		m_size++;
	}
	else
	{
		if((m_size) >= m_capacity)
		{
			m_capacity*=2;
			m_data->resize(m_capacity);
		}
		m_data->at(m_size-1) = p_element;
		int index = m_size-1;
		int pindex = getParentIndex(index);
		while( pindex >= 0 && ( m_data->at(index) > m_data->at(pindex)) )
		{
			// swap elements
			int temp = m_data->at(pindex);
			m_data->at(pindex) = m_data->at(index);
			m_data->at(index) = temp;
			index  = pindex;
			pindex = getParentIndex(index);
		}
		m_size++;

	}
}
int Heap ::extract()
{
	if(m_size==0)
		return -1;

	int temp =  m_data->at(0);
	m_data->at(0) = m_data->at(m_size-1);
	m_size--;
	int pindex = 0;
	int lindex = getLeftChildIndex(pindex);
	int rindex = getRightChildIndex(pindex);
	bool hasLeft = lindex < m_size;
	bool hasRight= rindex < m_size;
	bool rightGreater = hasRight ? (m_data->at(rindex) > m_data->at(pindex)): false;
	bool leftGreater  = hasLeft ? (m_data->at(lindex) > m_data->at(pindex)): false;
	while( (hasLeft || hasRight) && ( rightGreater || leftGreater) )
	{
		if(rightGreater && leftGreater)
		{
			if(m_data->at(rindex) > m_data->at(lindex))
			{
				int temp = m_data->at(pindex);
				m_data->at(pindex) = m_data->at(rindex);
				m_data->at(rindex) = temp;
				pindex = rindex;
			}
			else
			{
				int temp = m_data->at(pindex);
				m_data->at(pindex) = m_data->at(lindex);
				m_data->at(lindex) = temp;
				pindex = lindex;
			}
		}
		else if (rightGreater)
		{
			int temp = m_data->at(pindex);
			m_data->at(pindex) = m_data->at(rindex);
			m_data->at(rindex) = temp;
			pindex = rindex;
		}
		else
		{
			int temp = m_data->at(pindex);
			m_data->at(pindex) = m_data->at(lindex);
			m_data->at(lindex) = temp;
			pindex = lindex;
		}

		// Move index pointers forward for next iteration
		lindex = getLeftChildIndex(pindex);
		rindex = getRightChildIndex(pindex);
		hasLeft = lindex < m_size;
		hasRight= rindex < m_size;
		rightGreater = hasRight ? (m_data->at(rindex) > m_data->at(pindex)): false;
		leftGreater  = hasLeft ? (m_data->at(lindex) > m_data->at(pindex)): false;
	}

	return temp;
}

	std::ostream& operator<< (std::ostream& p_ostream, const Heap &p_obj)
	{
		p_ostream<<"Printing Heap Object , Type : Max Heap"<<std::endl;
		p_ostream<<"====================================================\n";
		for(int i = 0;  i < p_obj.m_size; i++)
		{
			std::cout<<p_obj.m_data->at(i)<<",  ";
		}
		p_ostream<<"\n====================================================\n";
		return p_ostream;
	}
}



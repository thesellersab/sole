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
#include <cstring>
#include <cmath>
template<typename tt_type>
void printVector(std::vector<tt_type> *data)
{
	std::cout<<"===============================\n";
	for (int i = 0; i < data->size(); ++i) {
		std::cout<<data->at(i)<<", ";
	}
	std::cout<<"\n";
	std::cout<<"===============================\n";
}

namespace maosikar {

Heap::Heap(int p_data[], int p_size)
{
	m_data = new std::vector<int>(p_size);
	m_size = p_size;
	m_capacity = p_size;
	// create a heap based on the input array
	std::memcpy(m_data->data(),p_data,sizeof(int)*p_size);
	heapify();

}
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
void Heap::swap(int p_index1, int p_index2)
{
	int temp = m_data->at(p_index1);
	m_data->at(p_index1) = m_data->at(p_index2);
	m_data->at(p_index2) = temp;
}
void Heap::pushMinDown(int p_index)
{
	int lindex = getLeftChildIndex(p_index);
	int rindex = getRightChildIndex(p_index);
	if(lindex < m_size || rindex < m_size )
	{
		bool hasRightChild = rindex <  m_size;
		bool hasLeftChild = lindex < m_size;
		int rightChild;
		int leftChild;

		if(hasRightChild)
			rightChild=m_data->at(rindex);
		if(hasLeftChild)
			leftChild=m_data->at(lindex);

		int parent = m_data->at(p_index);
		if(hasLeftChild && hasRightChild) // has both childs
		{
			if(rightChild > leftChild)
			{
				if(parent <  rightChild)
				{
					swap(p_index,rindex);
					pushMinDown(rindex);
				} // else do nothing terminate
			}
			else
			{
				if(parent < leftChild )
				{
					swap(p_index,lindex);
					pushMinDown(lindex);
;				}
			} // else recursion terminates current parent has correct value
		}
		else   // The node has only one of the children
		{
			if(hasLeftChild) // if has left child compare and swap
			{
				if(parent < leftChild)
				{
					swap(p_index,lindex);
					pushMinDown(lindex);
				}
			}
			else if(hasRightChild) // this case can't happen since in complete binary tree only right child is not possible
			{
				if(parent < rightChild)
				{
					swap(p_index,rindex);
					pushMinDown(rindex);
				}
			}
		}
	}
}
void Heap::pushMinDown2(int p_index)
{
	int lindex = this->getLeftChildIndex(p_index);
	int rindex = this->getRightChildIndex(p_index);
	bool lexists = lindex < this->m_size;
	bool rexists = rindex < this->m_size;
	int cindex=-1;
	if(lexists)
	{
		if(rexists)
		{
			cindex =(this->m_data->at(lindex))  >  (this->m_data->at(rindex)) ? lindex : rindex;
		}
		else
		{
			cindex = lindex;
		}
	}
	else if(rexists)
	{
		cindex = rindex;
	}
	if(cindex != -1)
	{
		if( (this->m_data->at(cindex)) > (this->m_data->at(p_index)) )
		{
			swap(cindex,p_index);
			this->pushMinDown2(cindex);
		}
	}
}
void Heap::heapify()
{
	float log2 = std::log2(m_size);
	int floor = (int)std::floor(log2);
	int start_index = (1<<floor)-2;
	std::cout<<"Input to Heapify function."<<std::endl;
	printVector<int>(m_data);
	for( int i = start_index; i >= 0; i--)
	{
		pushMinDown2(i);
		std::cout<<"Heapify iteration :"<<i<<std::endl;
		printVector<int>(m_data);
	}
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

				swap(pindex,rindex);
				pindex = rindex;
			}
			else
			{

				swap(pindex,lindex);
				pindex = lindex;
			}
		}
		else if (rightGreater)
		{
			swap(pindex,rindex);
			pindex = rindex;
		}
		else
		{
			swap(pindex,lindex);
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



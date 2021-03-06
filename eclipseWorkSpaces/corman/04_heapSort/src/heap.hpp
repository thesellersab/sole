/*

*     *     *     *     *     *     *     *     *     *		
	*     *     *     *     *     *     *     *     *   

                   || مصنف:موسیقار پروگرامر ||
    
    *     *     *     *     *     *     *     *     *		
*      *     *     *     *     *     *     *     *     *      


*/

/*
 * heap.hpp
 *
 *  Created on: Jun 26, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#ifndef SRC_HEAP_HPP_
#define SRC_HEAP_HPP_

#include <vector>
#include <iostream>
namespace maosikar {
	
class Heap {

public:
std::vector<int> *m_data;
int m_size;
int m_capacity;
	Heap();
	Heap(int data[], int size);
	Heap(int p_capacity);
	void insert(int p_element);
	void pushMinDown(int p_index);
	void pushMinDown2(int p_index);
	void heapify();
	void swap(int p_index1, int p_index2);
	int extract();
	int  getParentIndex(int p_childIndex);
	int  getLeftChildIndex(int p_parentIndex);
	int  getRightChildIndex(int p_parentIndex);
	friend std::ostream& operator<<(std::ostream& ostream, const Heap &p_obj);
};

}


#endif /* SRC_HEAP_HPP_ */

/*

*     *     *     *     *     *     *     *     *     *		
	*     *     *     *     *     *     *     *     *   

                   || مصنف:موسیقار پروگرامر ||
    
    *     *     *     *     *     *     *     *     *		
*      *     *     *     *     *     *     *     *     *      


*/

/*
 * vector.hpp
 *
 *  Created on: May 16, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */
#if 1
#ifndef SRC_VECTOR_HPP_
#define SRC_VECTOR_HPP_

namespace maosikar {

template <typename T_elem>
class vector
{
public:
	vector(int p_capacity=2);
	vector();
	void clear();
	long int size();
	long int capacity();
	void insert(T_elem &p_val);
	T_elem pop();
	void push(T_elem &p_val);
	T_elem peek();
	void swap(vector<T_elem> &avec);
	vector<T_elem>& operator=(vector<T_elem> &avec);
	T_elem& operator[](int index);
	T_elem& at(int index);
	void reserve(long int p_capacity);
	T_elem* data();
	~vector();
private:
	long int msize;
	long int mcapacity;
	T_elem *mdata;

};


}  // namespace maosikar

#endif /* SRC_VECTOR_HPP_ */
#endif

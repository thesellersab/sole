/*

*     *     *     *     *     *     *     *     *     *		
	*     *     *     *     *     *     *     *     *   

                   || مصنف:موسیقار پروگرامر ||
    
    *     *     *     *     *     *     *     *     *		
*      *     *     *     *     *     *     *     *     *      


*/

/*
 * vector.cpp
 *
 *  Created on: May 16, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#include "vector.hpp"
#include <assert.h>
namespace maosikar {


template<typename T_elem>
vector<T_elem>::vector(int p_capacity)
{
	mdata = new T_elem[p_capacity];
	msize = 0;
	mcapacity = p_capacity;
}

template<typename T_elem>
void vector<T_elem>::clear()
{
	delete[] this->mdata;
	this->msize = 0;
	this->mdata = new T_elem[2];
	this->mcapacity = 2;
}

template<typename T_elem>
long int vector<T_elem>::size()
{
	return this->msize;
}

template<typename T_elem>
long int vector<T_elem>::capacity()
{
	return this->mcapacity;
}

template<typename T_elem>
void vector<T_elem>::insert(T_elem &p_val)
{
	if(msize < mcapacity-1)
	{
		mdata[msize] = p_val;
		msize++;
	}
	else
	{
		// create new array with twice the size
		T_elem* newDataptr = new T_elem[2*mcapacity];
		// copy data to new array
		for (int i = 0; i < msize; ++i)
		{
			newDataptr[i] = mdata[i];
		}
		// delete old array and adjust member variables;
		delete[] mdata;
		mdata = newDataptr;
		mcapacity*=2;
		mdata[msize] = p_val;
		msize++;
	}
}

template<typename T_elem>
T_elem vector<T_elem>::pop()
{
	T_elem temp = mdata[msize];
	msize--;

}

template<typename T_elem>
T_elem* vector<T_elem>::data()
{
	return mdata;
}

template<typename T_elem>
void vector<T_elem>::push(T_elem &p_val)
{
	insert(p_val);
}

template<typename T_elem>
T_elem vector<T_elem>::peek()
{
	T_elem temp = mdata[size-1];
	return temp;
}

template<typename T_elem>
void vector<T_elem>::swap(vector<T_elem> &avec)
{
	T_elem* tptr = mdata;
	mdata = avec.data();
	avec.mdata = tptr;
	long int tsize = msize;
	long int tcapacity = mcapacity;
	msize = avec.size();
	mcapacity = avec.capacity();
	avec.msize = tsize;
	avec.mcapacity = tcapacity;
}

template<typename T_elem>
vector<T_elem>& vector<T_elem>::operator= (vector<T_elem> &avec)
{

}



template<typename T_elem>
T_elem& vector<T_elem>::operator[](int index)
{
	assert(index < msize);
	return mdata[index];
}

template<typename T_elem>
T_elem& vector<T_elem>::at(int index)
{
	assert(index < msize);

	return mdata[index];
}

template<typename T_elem>
void vector<T_elem>::reserve(long int p_capacity)
{
	if(p_capacity > mcapacity)
	{
		T_elem *newStorage = new T_elem[p_capacity];
		for(int i=0;i<msize;i++)
			newStorage[i] = mdata[i];
		delete mdata;
		mdata = newStorage;
	}
}

template<typename T_elem>
vector<T_elem>::~vector()
{
	delete mdata;
}
}  // namespace maosikar




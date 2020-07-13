/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *

                   || مصنف:موسیقار پروگرامر ||

    *     *     *     *     *     *     *     *     *
*      *     *     *     *     *     *     *     *     *


*/

/*
 * array_utilities.hpp
 *
 *  Created on: Jul 5, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#ifndef ARRAY_UTILITIES_HPP_
#define ARRAY_UTILITIES_HPP_
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

template <typename tt_type>
void print1DArray(tt_type *p_data, int p_size)
{
	for(int i = 0; i < p_size; i++)
	{
		std::cout<<p_data[i]<<", ";
	}
	std::cout<<std::endl;
}

enum SortType {en_Ascending, en_Descending};
template <typename tt_type>
bool checkSortedArray(tt_type *p_data, int p_size , SortType p_sortType )
{
	bool sorted =  true;
	for( int i = 0; i < p_size-1; i++)
	{
		if(p_sortType == en_Ascending)
		{
			if(p_data[i] > p_data[i+1])
			 return false;
		}
		else
		{
			if(p_data[i] < p_data[i+1])
			 return false;
		}
	}
	return sorted;
}

template <typename tt_type>
void genRandomArray(tt_type *p_data, int p_size)
{
	srand(time(NULL));
	for(int i = 0; i< p_size; i++)
	{
		tt_type temp = (tt_type)(rand() % p_size);
		p_data[i] = temp;
	}
}

template <typename tt_type>
void genEqualArray(tt_type *p_data, int p_size)
{
	srand(time(NULL));
	tt_type temp = (tt_type)(rand() % p_size);
	for(int i = 0; i< p_size; i++)
	{
		p_data[i] = temp;
	}
}

template <typename tt_type>
void genSortedAscendingArray(tt_type *p_data, int p_size)
{
	srand(time(NULL));
	tt_type temp = (tt_type)(rand() % p_size);
	for(int i = 0; i< p_size; i++)
	{
		p_data[i] = i+temp;
	}
}

template <typename tt_type>
void genSortedDescendingArray(tt_type *p_data, int p_size)
{
	srand(time(NULL));
	tt_type temp = (tt_type)(rand() % p_size);
	for(int i = 0; i< p_size; i++)
	{
		p_data[i] = p_size -i + temp;
	}
}

#endif /* ARRAY_UTILITIES_HPP_ */

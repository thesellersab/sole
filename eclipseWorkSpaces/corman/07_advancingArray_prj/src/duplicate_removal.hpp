/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *

                   || مصنف:موسیقار پروگرامر ||

    *     *     *     *     *     *     *     *     *
*      *     *     *     *     *     *     *     *     *


*/

/*
 * duplicate_removal.hpp
 *
 *  Created on: Jul 11, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#ifndef SRC_DUPLICATE_REMOVAL_HPP_
#define SRC_DUPLICATE_REMOVAL_HPP_

namespace maosikar {


template < typename tt_type>
int removeKey(tt_type *p_data, int p_key, int p_size)
{
	int copyIndex = 0;
	int keyCount=0;
	while(copyIndex < p_size && p_data[copyIndex]!=p_key)
	{
		copyIndex++;
	}
	if(p_data[copyIndex]==p_key)
		keyCount++;
	for(int i=copyIndex+1; i<p_size; i++)
	{
		if(p_data[i]!=p_key)
		{
			p_data[copyIndex++] = p_data[i];
		}
		else
		{
			keyCount++;
		}
	}
	return p_size - keyCount;
}
template < typename tt_type>
int removeDuplicates(tt_type *p_sortedData, int p_size)
{
	int cleanPointer=0;
	int indexPointer=0;
	while(indexPointer < p_size)
	{
		if(p_sortedData[cleanPointer]==p_sortedData[indexPointer])
		{
			indexPointer++;
		}
		else
		{
			p_sortedData[++cleanPointer] = p_sortedData[indexPointer];
			indexPointer++;
		}

	}
	return cleanPointer+1;
}


} // end of name space


#endif /* SRC_DUPLICATE_REMOVAL_HPP_ */

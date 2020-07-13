/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *

                   || مصنف:موسیقار پروگرامر ||

    *     *     *     *     *     *     *     *     *
*      *     *     *     *     *     *     *     *     *

*/

/*
 * traverse_2d_arrays.hpp
 *
 *  Created on: Jul 13, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */
#ifndef SRC_TRAVERSE_2D_ARRAYS_HPP_
#define SRC_TRAVERSE_2D_ARRAYS_HPP_
#include <cassert>
#include <cmath>
namespace maosikar {

template <typename tt_type, int tp_rows, int tp_cols>
void spiralTraversal(tt_type p_data[tp_rows][tp_cols], int p_spiralOrder[])
{
	assert(tp_rows == tp_cols);

	int numOfCircles = ceil(0.5 * (double)tp_cols);
	int sideLength = tp_rows - 1;
	int index=0;
	for ( int offset = 0; offset < numOfCircles; offset++)
	{
		int spiralSideLen = tp_rows - 1 - 2 * offset;
		int colIndex;
		if(spiralSideLen==0)
		{
			p_spiralOrder[index++] = p_data[offset][offset];
			return;
		}
		std::cout<<"spiral side len:" << spiralSideLen<<std::endl;
		// Generate the top side of the spiral
		int rowIndex = offset;
		for(colIndex=offset; colIndex < offset + spiralSideLen; colIndex++ )
		{
			p_spiralOrder[index++] = p_data[rowIndex][colIndex];
			std::cout<<rowIndex<<":"<<colIndex<<std::endl;
		}

		// Generate right side of the spiral
		colIndex = offset + spiralSideLen;
		for(rowIndex=offset; rowIndex < offset + spiralSideLen; rowIndex++ )
		{
			p_spiralOrder[index++] = p_data[rowIndex][colIndex];
			std::cout<<rowIndex<<":"<<colIndex<<std::endl;
		}

		// Generate bottom part of the spiral
		rowIndex = offset +  spiralSideLen;
		for(colIndex=offset + spiralSideLen; colIndex > offset ; colIndex-- )
		{
			p_spiralOrder[index++] = p_data[rowIndex][colIndex];
			std::cout<<rowIndex<<":"<<colIndex<<std::endl;
		}

		// Generate the left part of the spiral
		colIndex = offset;
		for(rowIndex=offset+spiralSideLen; rowIndex > offset; rowIndex-- )
		{
			p_spiralOrder[index++] = p_data[rowIndex][colIndex];
			std::cout<<rowIndex<<":"<<colIndex<<std::endl;
		}

	}
}

} // end of namespace maosikar
#endif /* SRC_TRAVERSE_2D_ARRAYS_HPP_ */

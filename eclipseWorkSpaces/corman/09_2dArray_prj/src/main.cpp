/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *

                   || مصنف:موسیقار پروگرامر ||

    *     *     *     *     *     *     *     *     *
*      *     *     *     *     *     *     *     *     *


*/

/*
 * main.cpp
 *
 *  Created on: Jul 13, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#include "utilities/array_utilities.hpp"
#include "traverse_2d_arrays.hpp"
using namespace maosikar;
using namespace std;
#define ROWS 3
#define COLS 3
int main( int argc, char *argv[])
{
	int data[ROWS][COLS];
	int order[ROWS*COLS];
	gen2DArrayCountingData<int,ROWS,COLS>(data);
	spiralTraversal<int,ROWS,COLS>(data,order);
	cout<<"The input array is:"<<std::endl;
	print2DArray<int,ROWS,COLS>(data);
	std::cout<<"The Array in Spiral Order:"<<std::endl;
	print1DArray(order,ROWS*COLS);

	return 0;
}



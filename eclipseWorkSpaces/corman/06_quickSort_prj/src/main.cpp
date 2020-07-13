/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *

                   || مصنف:موسیقار پروگرامر ||

    *     *     *     *     *     *     *     *     *
*      *     *     *     *     *     *     *     *     *


*/

/*
 * main.hpp
 *
 *  Created on: Jul 5, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#include "array_utilities.hpp"
#include "quick_sort.hpp"
#include <iostream>

int main( int argc, char *argv[])
{
	int size = 8;
	int sortAgain=0;
	if(argc > 1)
		size = atoi(argv[1]);
	if(argc > 2)
		sortAgain = atoi(argv[2]);
	if(argc > 3)
		sortAgain = atoi(argv[2]);

	int *data = new int[size];
	//genRandomArray<int>(data, size);
	//genSortedAscendingArray<int>(data, size);
	genEqualArray<int>(data, size);
	//print1DArray(data, size);
	quickSort2(data, size);
	std::cout<<"Sorted First Time ... "<<std::endl;

	if(sortAgain)
	{
		quickSort2(data, size);
		std::cout<<"Sorted Again"<<std::endl;
	}
	checkSortedArray(data, size, en_Ascending);
	//print1DArray(data, size);
	return 0;
}



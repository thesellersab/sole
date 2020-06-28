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
 *  Created on: Jun 26, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#include "heap.hpp"
#include <stdlib.h>
#include <time.h>

using namespace maosikar;


int main( int argc , char *argv[])
{
	typedef int dtype;
	srand(time(NULL));
	Heap myHeap((int)8);
	for ( int i = 0; i <  20; i++)
	{
		int temp = rand() % 200;
		myHeap.insert(temp);
	}
	std::cout<<myHeap;
	std::cout<<"Extract all the elements from Heap, they should be in Sorted Order"<<std::endl;
	for (int i = 0; i < 20; ++i)
	{
		std::cout<<myHeap.extract()<<",  ";
	}
	std::cout<<std::endl;
	return 0;
}



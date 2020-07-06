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
#include <stdio.h>
#include <time.h>

using namespace maosikar;


int main( int argc , char *argv[])
{
	int numElements=8;
	if(argc > 1)
	{
		numElements = atoi(argv[1]);
	}
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
	int last;
	for (int i = 0; i < 20; ++i)
	{
		if(i==0)
		{
			last = myHeap.extract();
			std::cout<<last<<",  ";
		}
		else
		{
			int current = myHeap.extract();
			if(last < current)
			{
				std::cout<<"\nOutput is not in correct order ... exit\n";
				exit(1);
			}
			std::cout<<current<<",  ";
		}
	}
	std::cout<<std::endl;

	std::cout <<"Testing Heapify Function ..."<<std::endl;
	int temp[8] = {6, 6, 7, 9, 8, 4, 5, 5};
	int *data = new int[numElements];
	for( int i=0; i< numElements; i++)
	{
		data[i] =temp[i];//rand() % 10;//numElements - i;// rand() % 10;
	}
	Heap myHeap2(data,numElements);
	std::cout<<myHeap2;
	std::cout<<"Extract all the elements from Heap, they should be in Sorted Order"<<std::endl;

	for (int i = 0; i < numElements; ++i)
	{
		if(i==0)
		{
			last = myHeap2.extract();
			std::cout<<last<<",  ";
		}
		else
		{
			int current = myHeap2.extract();
			if(last < current)
			{
				std::cout<<"\nOutput is not in correct order ... exit\n";
				exit(1);
			}
			std::cout<<current<<",  ";
		}
	}
	std::cout<<std::endl;


	return 0;
}



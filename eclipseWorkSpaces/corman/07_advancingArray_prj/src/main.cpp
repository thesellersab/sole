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
 *  Created on: Jul 11, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

//#define ADVANCE

#ifdef ADVANCE

#include "utilities/array_utilities.hpp"
#include "advancing_array_game.hpp"
using namespace maosikar;
int main ( int argc , char *argv[])
{
	int data[4] = {2,-10,0,1};
	print1DArray(data, 4);
	std::cout<<"----------Given Array-----------"<<std::endl;
	print1DArray(data,4);
	if(isStartToEndPossible(data,4))
		std::cout<<"Advancing through this array is POSSIBLE !"<<std::endl;
	else
		std::cout<<"Advancing through this array is NOT-POSSIBLE !"<<std::endl;
	int size = 32;
	bool flag = true;
	int *data2 = new int[size];
	while(flag)
	{
		genRandomArray(data2, size);
		flag = isStartToEndPossible(data2,size);
		print1DArray(data2,size);
	}
	std::cout<<"----------Given Array-----------"<<std::endl;
	print1DArray(data2,size);

	if(isStartToEndPossible(data2,size))
		std::cout<<"Advancing through this array is POSSIBLE !"<<std::endl;
	else
		std::cout<<"Advancing through this array is NOT-POSSIBLE !"<<std::endl;
	return 0;
}

#else

#include <iostream>
#include "duplicate_removal.hpp"
#include "utilities/array_utilities.hpp"
using namespace maosikar;
int main( int argc, char *argv[])
{
	int data[6] = {1,2,2,2,3,4};
	int data2[13] = {10,20,4,4,30,5,4,1,2,2,2,3,4};
	std::cout<<"------ Input Array:"<<std::endl;
	print1DArray(data, 6);
	int newLength = removeDuplicates(data, 6);
	std::cout<<"Array After Duplicate removal:"<<std::endl;
	print1DArray(data, newLength);
	std::cout<<"Remove key : 2 from Array:"<<std::endl;
	print1DArray(data2, 13);
	int newLength2 = removeKey(data2, 4, 13);
	print1DArray(data2, newLength2);

	return 0;
}
#endif

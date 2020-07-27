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
 *  Created on: Jul 19, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#include "test_vector.hpp"
#include <iostream>
int main ( int argc, char *argv[])
{
	testVector *vecPtr = new testVector(8);
	for (int i = 0; i < 8; ++i)
	{
		(*vecPtr)[i] = i;
		std::cout<<(*vecPtr)[i]<<std::endl;
	}
	testVector &vecRef = *vecPtr;
	for (int i = 0; i < 8; ++i)
	{
		vecRef[i] = i;
		std::cout<<(*vecPtr)[i]<<std::endl;
	}


	return 0;
}


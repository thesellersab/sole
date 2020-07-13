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
 *  Created on: Jul 3, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */
#include <iostream>
#include "fibonacci_series.hpp"
int main( int argc, char *argv[])
{
	for (int i = 0; i < 20; ++i) {
		std::cout<<"Fibonacci of ("<<i<<") = "<<fib(i)<<std::endl;
	}
	return 0;
}



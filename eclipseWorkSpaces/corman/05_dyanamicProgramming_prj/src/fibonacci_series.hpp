/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *

                   || مصنف:موسیقار پروگرامر ||

    *     *     *     *     *     *     *     *     *
*      *     *     *     *     *     *     *     *     *


*/

/*
 * fibonacci_series.hpp
 *
 *  Created on: Jul 3, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#ifndef SRC_FIBONACCI_SERIES_HPP_
#define SRC_FIBONACCI_SERIES_HPP_

int fibh(int x, int *mem)
{
	if(x< 2) // assuming x is always +ve
		return x;
	else if(mem[x]!=-1)
		return mem[x];
	else
	{
		mem[x] = fibh(x-1,mem) + fibh(x-2,mem);
		return mem[x];
	}
}
int fib(int x)
{
	int *mem = new int[x+1];
	for(int i=0;i < x+1 ; i++)
	{
		mem[i] = -1;
	}
	return fibh(x,mem);
}




#endif /* SRC_FIBONACCI_SERIES_HPP_ */

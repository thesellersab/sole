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
 *  Created on: Jul 12, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#include "utilities/array_utilities.hpp"
#include "stock_profits.hpp"
using namespace maosikar;
using namespace std;
int main( int argc, char *argv[])
{
	int data[8] = {10,9,8,7,6,5,4,3};
	cout<<"The input array is:"<<std::endl;
	print1DArray(data, 8);
	cout<<"The max profit fromt this array = "<<calculateMaxProfit(data, 8)<<endl;

	return 0;
}



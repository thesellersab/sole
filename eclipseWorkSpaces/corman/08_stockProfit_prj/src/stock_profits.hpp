/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *

                   || مصنف:موسیقار پروگرامر ||

    *     *     *     *     *     *     *     *     *
*      *     *     *     *     *     *     *     *     *


*/

/*
 * stock_profits.hpp
 *
 *  Created on: Jul 12, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#ifndef SRC_STOCK_PROFITS_HPP_
#define SRC_STOCK_PROFITS_HPP_
#include <limits>
#include <algorithm>
using namespace std;
template <typename tt_type>
tt_type calculateMaxProfit(tt_type *p_stockData, int p_length)
{
	tt_type maxProfit = std::numeric_limits<tt_type>::min();
	tt_type minPrice  = std::numeric_limits<tt_type>::max();
	for(int i=0; i< p_length; i++)
	{
		minPrice = min(minPrice,p_stockData[i]);
		maxProfit = max(maxProfit,p_stockData[i]-minPrice);
	}
	return maxProfit;
}


#endif /* SRC_STOCK_PROFITS_HPP_ */

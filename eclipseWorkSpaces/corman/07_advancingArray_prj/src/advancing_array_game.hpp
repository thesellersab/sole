/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *

                   || مصنف:موسیقار پروگرامر ||

    *     *     *     *     *     *     *     *     *
*      *     *     *     *     *     *     *     *     *


*/

/*
 * advancing_array_game.hpp
 *
 *  Created on: Jul 11, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */
#ifndef SRC_ADVANCING_ARRAY_GAME_HPP_
#define SRC_ADVANCING_ARRAY_GAME_HPP_


bool isStartToEndPossible(int *p_data, int p_length)
{
	bool rslt=false;
	int currentVisitedNode = 0 ;
	int creditToMove = p_data[currentVisitedNode++];
	while( creditToMove > 0 && currentVisitedNode < p_length)
	{
		creditToMove--;
		int nextNodeCredit = p_data[currentVisitedNode];
		creditToMove = creditToMove > nextNodeCredit ? creditToMove: nextNodeCredit;
		currentVisitedNode++;
	}
	if(currentVisitedNode == p_length)
		rslt = true;
	return rslt;
}


#endif /* SRC_ADVANCING_ARRAY_GAME_HPP_ */

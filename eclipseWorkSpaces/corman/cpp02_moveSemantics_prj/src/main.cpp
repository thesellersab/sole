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
 *  Created on: Jul 29, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

/*
 * Move Semantics examples
 */
#include <iostream>
using namespace std;
#include "entity_move_semantics.hpp"
using namespace maosikar;
int main() {
	Entity ent(String("AAA"));
	ent.printName()
;	return 0;
}

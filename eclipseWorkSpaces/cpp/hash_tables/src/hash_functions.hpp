/*

*     *     *     *     *     *     *     *     *     *		
	*     *     *     *     *     *     *     *     *   

                   || مصنف:موسیقار پروگرامر ||
    
    *     *     *     *     *     *     *     *     *		
*      *     *     *     *     *     *     *     *     *      


*/

/*
 * hash_functions.hpp
 *
 *  Created on: Jun 4, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */


#ifndef HASH_FUNCTIONS_HPP_
#define HASH_FUNCTIONS_HPP_

#include <string>

/*
 * Takes as input:
 * 					 the string whose hash function is to be calculated
 * 					 the base to be used for calculating the hash function
 * 					 prime number that is used for modulus operation, generally
 * 					 it is the size of hash table
 */

namespace maosikar {

static long long unsigned int calcHash(std::string &p_str, unsigned int p_base, unsigned int p_modPrime)
{
	long long unsigned int product = (long long unsigned int)p_str[p_str.length()-1];
	unsigned int strLen = p_str.length();
	for (int i = strLen-2; i >=0; i--)
	{
		product = (product * p_base) % p_modPrime;
		product = (product + (long long unsigned int)(p_str[i])) % p_modPrime;
	}
	return product;
}

}



#endif /* HASH_FUNCTIONS_HPP_ */

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
 *  Created on: Jul 20, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */
#include <unordered_set>
#include <iostream>
#include <functional>
int main(int argc , char *argv[])
{
	std::unordered_set<int> aSet;
	aSet.insert(50);
	auto it = aSet.begin();
	std::cout<<*it<<std::endl;

	std::unordered_set<std::string> myset;
	std::cout << "0. size: " << myset.size() << std::endl;

	myset = {"milk","potatoes","eggs"};
	std::cout << "1. size: " << myset.size() << std::endl;

	myset.insert ("pineapple");
	std::cout << "2. size: " << myset.size() << std::endl;

	myset.erase ("milk");
	std::cout << "3. size: " << myset.size() << std::endl;

	return 0;
}

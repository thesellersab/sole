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
#include <set> // implemented as Binary Search Tree
/*
 * APIs to set can be divided in following categories
 *
 *  1) Member:
 *  	Constructors and Destructors, and COPY operator=
 *
 *  2) Iterators:
 *  Iterators: begin,end, rbegin, rend, cbegin, cend, crbegin, crend
 *
 *  3) Capacity: size, max_size, empty
 *
 *
 *  4) Modifiers : insert , erase , swap, clear , emplace , emplace_hint
 *
 *	5) Operattion : find, count , lower_bound, upper_bound, equal_range
 *
 * */
#include <iostream>
#include <functional>

class CompareInt{
public:
	bool operator() (int x, int y)
	{
		return x < y;
	}
};

int main ( int argc, char *argv[])
{
	std::set<int, CompareInt> aSet;
	std::set<int, std::less<int> > bSet;
	std::set<int, std::greater<int> > cSet;
	for (int i = 0; i < 8; ++i)
	{
		aSet.insert(i);
		bSet.insert(i);
		cSet.insert(i);
	}

	for(int a:aSet)
	{
		std::cout<<a<<std::endl;
	}
	for(int a:bSet)
	{
		std::cout<<a<<std::endl;
	}
	for(int a:cSet)
	{
		std::cout<<a<<std::endl;
	}
	return 0;
}

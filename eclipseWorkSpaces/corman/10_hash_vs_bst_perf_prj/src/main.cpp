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
 *  Created on: Jul 23, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */


#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;
#include <chrono>

#define  TEST_LEN (1<<15)

// Create a map and insert p_Len random elements then find and delete
template < typename tt_SomeMap,  int tp_len>
void testMapCreation(tt_SomeMap &p_aMap)
{
	for (int i = 0; i < tp_len; ++i)
	{
		p_aMap[i] = i;
	}
	int i=0;
	while(!p_aMap.empty())
	{
		auto it = p_aMap.find(i++);
		p_aMap.erase(it);
	}
}
template < int p_len>
void testOrderedMap()
{
	map<int,int> aMap;
	testMapCreation<map<int,int>,p_len>(aMap);
}

template < int p_len>
void testUnOrderedMap()
{
	unordered_map<int,int> aMap;
	testMapCreation<unordered_map<int,int>,p_len>(aMap);
}
int main(int argc, char *argv[])
{
	//std::chrono::time_point<std::chrono::high_resolution_clock> timePoint1, timePoint2;

	auto timePoint1 = std::chrono::high_resolution_clock::now();
	testUnOrderedMap<TEST_LEN>();
	auto timePoint2 = std::chrono::high_resolution_clock::now();
	testOrderedMap<TEST_LEN>();
	auto timePoint3 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration1= timePoint2 -  timePoint1;
	std::chrono::duration<double> duration2= timePoint3 -  timePoint2;
	std::cout<<"Total Time Consumed for Unordered map:"<<duration1.count()<<" Seconds\n";
	std::cout<<"Total Time Consumed for ordered map:"<<duration2.count()<<" Seconds\n";

	return 0;
}



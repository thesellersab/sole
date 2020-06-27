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
 *  Created on: May 16, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#include <vector>
#include <iostream>
#include <algorithm> //copy
#include <iterator>

void testStdVector()
{
	typedef std::vector<int> ivector;
	ivector intvec;
	for (int var = 0; var < 8; ++var)
	{
		intvec.push_back(var);
	}
	ivector::iterator iterbegins = intvec.begin();
	ivector::const_iterator iterbeginconst = intvec.cbegin();
	auto iterbegin = intvec.begin();
	auto end  = intvec.end();
	auto savedIter = iterbegin;
	iterbegin[3] =  456;
	std::cout<<"Printing std::vector using WHILE loop"<<std::endl;
	while(iterbegin != end)
	{
		std::cout<<"Values:"<<*iterbegin<<std::endl;
		std::cout<<"Values:"<<iterbegin[0]<<std::endl;
		iterbegin++;
	}
	std::cout<<"Printing std::vector using FOR loop"<<std::endl;
	for(auto it=intvec.begin(); it!=intvec.end();it++)
	{
		std::cout<<*it;
	}
	std::cout<<std::endl;
	std::cout<<"Printing using ostream output iterator"<<std::endl;

	std::ostream_iterator<int> osit(std::cout,"-~-");
	std::copy(intvec.begin(),end,osit);
	std::copy(intvec.begin(),end,osit);
	std::copy(intvec.begin(),end,osit);
	std::copy(intvec.begin(),end,osit);
}



#include <iostream>


int main(int argc, char **argv) {
	testStdVector();
	std::cout << "Hello World !"<<std::endl;
	return 0;
}

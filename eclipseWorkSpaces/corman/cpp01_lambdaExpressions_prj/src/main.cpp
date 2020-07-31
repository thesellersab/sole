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
 *  Created on: Jul 28, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

/*
 * Lambda expression examples
 */

#include <iostream>
#include <functional>
#include <vector>
// Declare a function that takes as input a function pointer

// OLD Style function argument passing
void vecPrint(std::vector<int> &aVec, void(*func)(std::vector<int>,int,int) )
{
	func(aVec,0,aVec.size());
}


// new style function pointer passing using std::functional
void vecPrint2(std::vector<int> &aVec, std::function<void(std::vector<int>,int,int)> func)
{
	func(aVec,0,aVec.size());
}

using namespace std;

int main()
{
	int a=10;
	int b=20;
	int c=30;
	// declare and call lambda function on the spot
	[a]()
	{
		std::cout<<"Lambda expression called on the spot.\n";
		std::cout<<"The parameter captured as value:"<<a<<std::endl;
	}(); // () at the end mark for calling the function

	[&a]()
	{
		std::cout<<"Lambda expression called on the spot.\n";
		std::cout<<"The parameter captured by reference:"<<a<<std::endl;
		a++;
	}(); // () at the end mark for calling the function

	[=](int x)
	{
		std::cout<<"Lambda expression called on the spot.\n";
		std::cout<<"All variables in context captured as values:"<<a<<std::endl;
		std::cout<<"a="<<a<<" b="<<b<<"c="<<c<<std::endl;
	}(20); // () at the end mark for calling the function

	auto f1 = [&](int x)
	{
		std::cout<<"Lambda function using auto with arguments\n";
		std::cout<<"The parameter x has value:"<<x<<std::endl;
		a++,
		b++;
		c++;
	};
	f1(200);

	auto vecP = [](std::vector<int> avec,int a,int b)
	{
		for (int i = a; i < b; ++i) {
			std::cout<<avec[i]<<std::endl;
		}
	};

	auto vecP2 = [](std::vector<int> avec,int a,int b)
	{
		for (int i = a; i < b; ++i) {
			std::cout<<avec[i]<<" Fancy Vector print"<<std::endl;
		}
	};
	std::vector<int> avec = {1,2,3,4,5,6,7,8};
	vecPrint(avec, vecP);
	vecPrint(avec, vecP2);
	vecPrint2(avec, vecP);
	vecPrint2(avec, vecP2);

	return 0;
}

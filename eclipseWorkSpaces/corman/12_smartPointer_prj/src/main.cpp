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
 *  Created on: Jul 25, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#include <iostream>
#include <memory>

using namespace std;

class TestClass
{
public:
	int m_x;
	TestClass(int p_a)
	{
		m_x=p_a;
	}

	~TestClass()
	{
		cout<<"Calling Destructor\n";
	}
};
int main(int argc, char *argv[])
{
	unique_ptr<TestClass> uptr = make_unique<TestClass>(20);
	auto uptr2 = make_unique<TestClass>(20);
	unique_ptr<TestClass> uptr3(new TestClass(20));

	// get data member in smart pointers can be used to get the raw pointer for passsing
	//to functions that execept raw pointers
	unique_ptr<int[]> smartIntPt(new int[1000]);
	for (int i = 0; i < 1000; ++i)
	{
		smartIntPt[i] = i;
	}
	auto p = make_unique<int[]>(5);
	for (int i = 0; i < 5; ++i)
	{
		p[i] = i;
	}

	return 0;
}

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
 *  Created on: Jul 22, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */
#include <iostream>
#include <map>
using namespace std;

template <class a>
void disp(a val)
{
	cout<<val<<endl;
}
template <class a>
void dispn(a val)
{
	cout<<val;
}
template <class b>
void printMap(b &val)
{
	for(auto &a : val)
	{
		dispn("<");
		dispn(a.first);
		dispn(" , ");
		dispn(a.second);
		dispn(" >, ");
	}
	disp("");

}
void testMapConstructors()
{
	// Empty Constructors:
	map<string,int> aMap;
	aMap["RollNumber"] = 22;
	aMap["section"] = 1;
	aMap["height"] = 511;
	aMap["age"] = 34;
	disp(aMap.size());
	auto itb = aMap.cbegin();
	auto ite = aMap.cend();
	for(;itb!=ite; itb++)
	{
		//disp((*itb).first);
		//disp((*itb).second);
		auto pairOut = *itb;
		auto key = itb->first;
		auto mappedVal = itb->second;
		disp(key);
		disp(mappedVal);
	}

	// Copy Constructor
	auto bMap =  aMap;
	disp("Print b Maps --------");
	printMap(bMap);

	// Range Based Constructors
	auto cMap = decltype(aMap)(aMap.cbegin(),aMap.cend());
	cMap["mapNumber"] = 3;

	// Initializer list based constructors
	decltype(cMap) a;
	printMap(cMap);
	pair<string,int> aPair = {"Shahzad Ahmad Butt", 22};
	pair<string,int> bPair = {"Aashir", 200};
	pair<string,int> cPair = {"Aashir", 23};
	disp(aPair.first);

	//cout<<"Pair Vals:"<<aPair;
	map<string, int> dMap = {aPair,cPair,{"Mahmood",786}};
	dMap.insert(cPair);
	dMap.at("Mahmood") = 34677;
	std::cout<<dMap.at("Mahmood")<<std::endl;
	disp(dMap["Aashir"]);
	disp(dMap.size());
	printMap(dMap);


}

void testMapInsertionMethods()
{
	map<string, int> aMap;
	aMap["shahzad"] = 22;
	aMap["Mahmood"] = 15;
	auto ret = aMap.insert(pair<string,int>("Aashir",2));
	pair<map<string,int>::iterator,bool> ret2 = aMap.insert(pair<string,int>("Aalam",2));
	if(ret2.second==true)
		disp("Element was inserted successfully");
	ret = aMap.insert(pair<string,int>("Aashir",20));
	if(ret.second==true)
		disp("Element was inserted successfully.");
	else
	{
		disp("Element already existed");
		disp((ret.first)->second);
	}
}

void testMapEraseMethods()
{
	map<char, int> aMap;
	aMap['a'] = 10;
	aMap['b'] = 20;
	aMap['c'] = 30;
	aMap['d'] = 40;
	aMap['e'] = 50;
	disp("Orginal Map");
	printMap(aMap);
	// Erase using Key
	aMap.erase('a');
	disp("Map after deleting key a");
	printMap(aMap);
	auto it = aMap.find('d');
	disp("The key for find 30");
	disp(it->first);
	disp(it->second);
	disp("delete value 30 to end using iterator");
	// Erase using iterator range
	aMap.erase(it,aMap.end());
	disp("Map Afte Deleting range form 30 to end");
	printMap(aMap);
	//Erase using iterator to single element
	auto it2 =  find.aMap('b');
	aMap.erase(it2);
	disp("Map after deleted b");
	printMap(aMap);
}

int main()
{
	//testMapConstructors();
	//testMapInsertionMethods();
	testMapEraseMethods();

	return 0;
}

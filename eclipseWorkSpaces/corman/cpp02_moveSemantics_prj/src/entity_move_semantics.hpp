/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *

                   || مصنف:موسیقار پروگرامر ||

    *     *     *     *     *     *     *     *     *
*      *     *     *     *     *     *     *     *     *


*/

/*
 * entity_move_semantics.hpp
 *
 *  Created on: Jul 29, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

/*
 * In this file two classes or build to pratice move sematics
 * basics.
 */

#ifndef ENTITY_MOVE_SEMANTICS_HPP_
#define ENTITY_MOVE_SEMANTICS_HPP_
#include <cstring>
#include <iostream>
namespace maosikar{
class String
{

	char *m_data;
	int m_size;
public:
	//String() = default;
	String(const char *p_data)
	{
		m_size = strlen(p_data);
		m_data = new char[m_size];
		std::memcpy(m_data,p_data,m_size);

	}
	// Copy Constructor
	String (const String &p_str)
	{
		std::cout<<"Copied"<<std::endl;
		m_size = p_str.m_size;
		m_data = new char[m_size];
		std::memcpy(m_data,p_str.m_data,m_size);
	}
	// Move Constructor
	String (String &&p_str)
	{
		std::cout<<"Moved"<<std::endl;
		m_size = p_str.m_size;
		m_data = p_str.m_data;
		p_str.m_size = 0;
		p_str.m_data = nullptr;
	}
	void print()
	{
		std::cout<<"Priting Name\n";
		for (int i = 0; i < m_size; ++i) {
			std::cout<<(m_data[i]);
		}
		std::cout<<std::endl;
	}
	~String()
	{
		std::cout<<"Destroyed"<<std::endl;
		delete []m_data;
	}
};


class Entity
{
	String m_name;
public:
	Entity(String &p_str):m_name(p_str)
	{

	}
	Entity(String &&p_name):m_name(std::move(p_name))
	{

	}
	void printName()
	{
		m_name.print();
	}
	~Entity() = default;
};


};


#endif /* ENTITY_MOVE_SEMANTICS_HPP_ */

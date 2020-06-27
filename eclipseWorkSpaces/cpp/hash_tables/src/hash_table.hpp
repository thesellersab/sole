/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *   

                   || مصنف:موسیقار پروگرامر ||
    
    *     *     *     *     *     *     *     *     *		
*      *     *     *     *     *     *     *     *     *      


*/

/*
 * hash_table.hpp
 *
 *  Created on: Jun 4, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#ifndef SRC_HASH_TABLE_HPP_
#define SRC_HASH_TABLE_HPP_

/*
 * 	The class is designed to manage hashing of class objects which
 * 	provide a function namely key which returns a string key
 */

#include "hash_functions.hpp"
#include <vector>
#include <iostream>
namespace maosikar {
template <typename tp_T,   int tp_tableLen>
class HashTable
{
	typedef std::vector<tp_T>* t_ObjVectorPointer;
	std::vector<t_ObjVectorPointer> *m_hashTable;
	long unsigned int m_tableSize;
	long unsigned int m_tableCapacity;
	long unsigned int m_numHashed;

public:
	HashTable(int a)
	{
		m_hashTable = new std::vector<t_ObjVectorPointer>(tp_tableLen+a);
		m_tableSize = tp_tableLen;
		m_tableCapacity = tp_tableLen;
		m_numHashed = 0;
		std::cout<<"Inside hash table constructor"<<std::endl;
		for(int i=0; i < m_hashTable->size(); i++)
		{
			if((*m_hashTable)[i] == nullptr)
				std::cout<<"Pointer at index:" <<i<< "is nullptr"<<std::endl;
			else
				std::cout<<"The pointer is not NULL"<<std::endl;
		}
	}
	~HashTable()
	{
		delete m_hashTable;
	}
	void print()
	{
		std::cout<<"From hash table print is called"<<std::endl;
	}

	//void hashObj(tp_T &p_obj);
	//tp_T getObj(std::string &p_key);
};

}
#endif /* SRC_HASH_TABLE_HPP_ */

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
 *  Created on: Jun 3, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#include "student.hpp"
#include "hash_functions.hpp"
#include "hash_table.hpp"
//#define TEST_STUDENT_CLASS
#define TEST_HASH

void testStudent()
{
#ifdef TEST_STUDENT_CLASS

	using namespace maosikar;
	Student st1("Aashir Shahzad", 37);
	std::cout<<st1;
#endif
}




void test_hash_functions()
{
#ifdef TEST_HASH
	using namespace maosikar;
	std::string name("Shahzad");
	std::string name1("Mahmood");
	std::string name2("Aashir");
	Student st1("Alice",37);

	unsigned int tableLen = 7919;
	unsigned int base = 10;
	unsigned int mod = tableLen;
	std::cout<<"Hash of: "<<name<<" is : "<<calcHash(name,base,mod)<<std::endl;
	std::cout<<"Hash of: "<<name1<<" is : "<<calcHash(name1,base,mod)<<std::endl;
	std::cout<<"Hash of: "<<name2<<" is : "<<calcHash(name2,base,mod)<<std::endl;


#endif
}
int main(int argc, char **argv)
{
	using namespace maosikar;
	//testStudent();
	//test_hash_functions();
	HashTable<int,347> ptr(45);
	std::vector<int> vec;
	vec.size();
	ptr.print();
	std::cout<<"Ran all the tests"<<std::endl;
}





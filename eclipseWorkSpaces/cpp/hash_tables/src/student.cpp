/*

*     *     *     *     *     *     *     *     *     *		
	*     *     *     *     *     *     *     *     *   

                   || مصنف:موسیقار پروگرامر ||
    
    *     *     *     *     *     *     *     *     *		
*      *     *     *     *     *     *     *     *     *      


*/

/*
 * student.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#include "student.hpp"
namespace maosikar {
std::string Student::getName()
{
	return this->mname;
}

void Student::setName(std::string &pname)
{
	this->mname = pname;
}

void Student::setID(int pid)
{
	this->mid = pid;
}

int Student::getID()
{
	return this->mid;
}

Student::Student(std::string pname, int pid)
{
	this->mname = pname;
	this->mid = pid;
}

Student::~Student()
{

}

std::ostream& operator<< (std::ostream &outstr, const Student &pstudent)
{
	outstr <<"Name: "<<pstudent.mname<<std::endl;
	outstr <<"ID: "<<pstudent.mid<<std::endl;
}


}


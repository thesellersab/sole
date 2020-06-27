/*

*     *     *     *     *     *     *     *     *     *		
	*     *     *     *     *     *     *     *     *   

                   || مصنف:موسیقار پروگرامر ||
    
    *     *     *     *     *     *     *     *     *		
*      *     *     *     *     *     *     *     *     *      


*/

/*
 * student.hpp
 *
 *  Created on: Jun 3, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#ifndef SRC_STUDENT_HPP_
#define SRC_STUDENT_HPP_

#include <string>
#include <iostream>
namespace maosikar {
class Student {
public:
	Student(std::string pname, int pid);
	std::string getName();
	void setName(std::string &pname);
	void setID(int pid);
	int getID();
	~Student();
	friend std::ostream& operator<<(std::ostream &outstr, const Student &pstudent);
private:
	int mid;
	std::string mname;
};

}


#endif /* SRC_STUDENT_HPP_ */

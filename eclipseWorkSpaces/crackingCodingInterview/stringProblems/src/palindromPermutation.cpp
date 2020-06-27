/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *

                   || مصنف:موسیقار پروگرامر ||

    *     *     *     *     *     *     *     *     *
*      *     *     *     *     *     *     *     *     *

/*
 * palindromPermutation.cpp
 *
 *  Created on: Jun 10, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */
#include "test_selector.hpp"
#ifdef PALINDROME_STRING_TEST
#include <string>
#include <iostream>

void tolowerCase(std::string &p_str)
{
	for(auto &c:p_str)
	{
		c = std::tolower(c);
	}
}

bool isPalindrome(std::string &p_str)
{
	std::string str(p_str);
	tolowerCase(p_str);
	int freqs[26];
	for(int i=0; i<26; i++)
	{
		freqs[i] = 0;
	}
	for(auto c : str)
	{
		int index = c - 'a';
		freqs[index]++;
	}
	int count=0;
	for(int i=0; i<26; i++)
	{

		if(freqs[i] % 2 != 0 )
			count++;
		if(count > 1)
			return false;
	}
	return true;
}

int main(int argc, char **argv) {
	using namespace std;
	string str("aabxzbaa");
	tolowerCase(str);
	cout<<str<<endl;
	bool bl = isPalindrome(str);
	if(bl)
		cout<< "True"<<endl;
	else
		cout<< "false"<<endl;

}
#endif



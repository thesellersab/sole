/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *

                   || مصنف:موسیقار پروگرامر ||

    *     *     *     *     *     *     *     *     *
*      *     *     *     *     *     *     *     *     *


*/

/*
 * csv_parse_utilities.hpp
 *
 *  Created on: Jul 26, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */


#ifndef CSV_PARSE_UTILITIES_HPP_
#define CSV_PARSE_UTILITIES_HPP_
#include <string>
#include <vector>
#include <fstream>
/*
 * splitString : Function to split string based to the separator charter
 */

void splitString(std::string p_record, char p_seperator, std::vector<std::string> &p_fields)
{
	if(p_record=="")
		return;

	std::size_t field_start = 0;
	std::size_t field_end = p_record.find(p_seperator);
	std::size_t recordLength = p_record.length();
	while(field_start < recordLength )
	{
		if(field_end > recordLength )
		{
			if(field_start < recordLength) // last record, no coma at the end
			{
				p_fields.emplace_back(p_record.substr(field_start,recordLength-field_start));
			}
			field_start = recordLength;
		}
		else // else extract a field
		{
			p_fields.emplace_back(p_record.substr(field_start,field_end-field_start));
			field_start = field_end+1;
		}
		field_end = p_record.find(p_seperator,field_start);
	}

}

std::vector<std::vector<std::string>> readCsvRecords(std::string p_filePath, char p_seperator)
{
	std::vector<std::vector<std::string>> records;
	std::string recordLine;
	std::fstream iFileStream;
	iFileStream.open(p_filePath,std::ios::in);
	if(iFileStream.is_open())
	{
		while(std::getline(iFileStream,recordLine))
		{
			std::vector<std::string> aRecord;
			splitString(recordLine, ',', aRecord);
			records.emplace_back(aRecord);
		}
	}
	else
	{
		std::cout<<"The file :"<<p_filePath<<" Cannot be opened !!!"<<std::endl;
		exit(1);
	}

	return records;
}

#endif /* CSV_PARSE_UTILITIES_HPP_ */

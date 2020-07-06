/*
 * merge_sort.cpp
 *
 *  Created on: Jun 20, 2020
 *      Author: shahzadb
 */

#include <iostream>
#include <stdlib.h>
//#define DEBUG
#ifdef DEBUG
#define PR(var) std::cout<<#var<<"== "<<var<<std::endl;
#else
#define PR(var) ;
#endif
template <typename tt_type>
void print1DArray(tt_type *p_data, unsigned long p_size)
{
	for(int i = 0; i < p_size; i++)
	{
		std::cout<<p_data[i]<<", ";
	}
	std::cout<<std::endl;
}

enum SortType {en_Ascending, en_Descending};
template <typename tt_type>
bool checkSortedArray(tt_type *p_data, int p_size , SortType p_sortType )
{
	bool sorted =  true;
	for( int i = 0; i < p_size-1; i++)
	{
		if(p_sortType == en_Ascending)
		{
			if(p_data[i] > p_data[i+1])
			 return false;
		}
		else
		{
			if(p_data[i] < p_data[i+1])
			 return false;
		}
	}
	return sorted;
}

#include <stdlib.h>
void merge(int *p_data, unsigned long p_low, unsigned long p_middle, unsigned long p_high)
{
	int size = p_high - p_low + 1;
	int *sortedArray = (int *)malloc(size * sizeof(int));
	unsigned long lowPointer =  p_low;
	unsigned long middlePointer = p_middle;
	for(int i = 0; i < size; i++)
	{
		// case : when low:midle has elements to copy
		if(lowPointer <= p_middle)
		{
			if(middlePointer < p_high)
			{
				if(p_data[lowPointer] < p_data[middlePointer+1])
				{
					sortedArray[i] = p_data[lowPointer];
					lowPointer++;
				}
				else
				{
					sortedArray[i] = p_data[middlePointer+1];
					middlePointer++;
				}
			}
			else
			{
				sortedArray[i] = p_data[lowPointer];
				lowPointer++;
			}
		}
		else
		{
			sortedArray[i] = p_data[++middlePointer];
		}
	}
	for( int i = 0; i < size; i++)
	{
		p_data[p_low+i] = sortedArray[i];
	}
	//std::memcpy(data,sortedArray,size*sizeof(int));
}


void mergeSorter(int *p_data, unsigned long p_low, unsigned p_high)
{
	PR(p_high);
	if(p_low == p_high)
		return;
	else
	{
		unsigned long middle = (p_low + p_high)/2;
		PR(middle);
		mergeSorter(p_data, p_low ,middle);
		mergeSorter(p_data, middle+1, p_high);
		merge(p_data,p_low,middle,p_high);
	}
}

void mergeSort( int *data, int size)
{
	mergeSorter(data,0,size-1);
}

#define SIZE  8
int main(int argc, char **argv) {
	int data[8] = {90,51,1,10,-270,-2,30,400};
	//int data[SIZE] = {20,10};
	print1DArray(data, SIZE);
	mergeSort(data,SIZE);
	print1DArray(data, SIZE);
	if(!checkSortedArray(data, SIZE, en_Ascending))
		std::cout<<"Array was ~NOT Sorted~ in Correct Order..."<<std::endl;
	else
		std::cout<<"Array was ~Sorted~ in Correct Order..."<<std::endl;

	return 0;
}

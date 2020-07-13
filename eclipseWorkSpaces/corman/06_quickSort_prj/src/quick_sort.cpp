/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *

                   || مصنف:موسیقار پروگرامر ||

    *     *     *     *     *     *     *     *     *
*      *     *     *     *     *     *     *     *     *


*/

/*
 * quick_sort.cpp
 *
 *  Created on: Jul 5, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#include "quick_sort.hpp"
void swap(int *p_data, int p_index1, int p_index2)
{
	int temp =  p_data[p_index1];
	p_data[p_index1] =  p_data[p_index2];
	p_data[p_index2] = temp;
}
int partition(int *p_data, int p_low, int p_high)
{
	int pivot_index = p_high;
	int pivot = p_data[pivot_index];
	int startPartSmall = p_low - 1;
	int endPartLarge;
	for(endPartLarge=p_low; endPartLarge <p_high; endPartLarge++)
	{
		if(p_data[endPartLarge] < pivot)
		{
			startPartSmall++;
			swap(p_data,startPartSmall,endPartLarge);
		}
	}
	swap(p_data,startPartSmall+1,pivot_index);
	return (startPartSmall+1);

}
void quickSort(int *p_data, int p_low, int p_high)
{
	if(p_low < p_high)
	{
		int pivot_index = partition(p_data,p_low,p_high);
		quickSort(p_data,p_low,pivot_index-1);
		quickSort(p_data,pivot_index+1,p_high);
	}
}
void quickSort(int *p_data, int p_size)
{
	quickSort(p_data,0,p_size-1);
}
void partition2(int *p_data, int p_low, int p_high, int &p_equalStart, int &p_equalEnd)
{
	int smallPtr = p_low;
	int equalPtr = p_low;
	int largePtr = p_high+1;
	int pivot_index = (p_high-1 + p_low)/2;
	int pivot = p_data[pivot_index];
	while(equalPtr <  largePtr)
	{
		if(p_data[equalPtr] < pivot)
		{
			swap(p_data,equalPtr++,smallPtr++);
		}
		else if(p_data[equalPtr] == pivot)
		{
			equalPtr++;
		}
		else
		{
			swap(p_data,equalPtr,--largePtr);
		}
	}
	p_equalStart = smallPtr;
	p_equalEnd = largePtr-1;
}
void quickSort2(int *p_data, int p_low, int p_high)
{
	if(p_low < p_high)
	{
		int equalStart, equalEnd;
		partition2(p_data,p_low,p_high,equalStart,equalEnd);
		quickSort2(p_data,p_low,equalStart-1);
		quickSort2(p_data,equalEnd+1,p_high);
	}
}
void quickSort2(int *p_data, int p_size)
{
	quickSort2(p_data,0,p_size-1);
}




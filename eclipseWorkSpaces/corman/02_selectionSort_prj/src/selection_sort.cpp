/*
 * selection_sort.cpp
 *
 *  Created on: Jun 20, 2020
 *      Author: shahzadb
 */

#include <iostream>

template <typename tt_type>
void print1DArray(tt_type *data, unsigned long size)
{
	for(int i = 0; i < size; i++)
	{
		std::cout<<data[i]<<", ";
	}
	std::cout<<std::endl;
}

template <typename tt_type>
void swap(tt_type &x, tt_type &y)
{
	tt_type temp =  x;
	x = y;
	y = temp;
}
template <typename tt_type>
void selectionSort(tt_type data[], unsigned long size)
{
	int minIndex = 0;
	for(int i = 0; i < size; i++)
	{
		minIndex = i;
		for(int j = i+1; j < size; j++)
		{
			if(data[minIndex] > data[j])
				minIndex = j;
		}
		swap(data[i],data[minIndex]);
	}
}


#define SIZE 8
typedef double t_data;
int main(int argc, char **argv)
{
	//int data[SIZE];
	//int *data = new int[SIZE];
	t_data *data = (t_data *)malloc(SIZE*sizeof(t_data));
	for(int i=0; i < SIZE; i++)
	{
		data[i] = SIZE - i -1;
	}
	std::cout<<"Unsorted Array:"<<std::endl;
	print1DArray(data, SIZE);
	selectionSort(data,SIZE);
	std::cout<<"Sorted Array"<<std::endl;
	print1DArray(data, SIZE);
	return 0;
}

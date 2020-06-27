//============================================================================
// Name        : insertionSort.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iterator>
#include <array>
using namespace std;
#define N 8
template <typename tp_type>
void insertionSort2(tp_type data[], int size)
{
	for(int j=1; j<size; j++)
	{
		tp_type key = data[j];
		int i = j -1;
		while(i >= 0 && data[i] > key)
		{
			data[i+1] = data[i];
			i--;
		}
		data[i+1] = key;
	}
}

template <typename tp_type>
void insertionSort(tp_type data[], int size)
{
	for(int i=1; i<size; i++)
	{
		tp_type key = data[i];
		int j = i -1;
		while(j >= 0 && key < data[j])
		{
			data[j+1] = data[j];
			j--;
		}
		data[j+1] = key;

	}
}

template <typename tp_type, long unsigned int size>
void insertionSort(std::array<tp_type, size> &data)
{
	insertionSort<tp_type>(data.data(),data.size());
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	typedef array<int,N> array8;
	array8 data;
	for (int i = 0; i < N; ++i) {
		data[i] = 8-i;
	}
	insertionSort(data);
	std::copy(data.begin(), data.end(),std::ostream_iterator<int>(std::cout,"--"));
	return 0;
}

#ifndef __ITER_H__
#define __ITER_H__
#include <iostream>

template <typename array, typename func>
void iter(array *arr, size_t size, func f){
	size_t i = 0;

	while (i < size)
	{
		f(arr[i]);
		i++;
	}
};

#endif
#ifndef __EASYFIND_H__
#define __EASYFIND_H__
#include <iterator>

template <typename T>
typename T::iterator easyfind ( T& container, int n ) {
	return (std::find(container.begin(), container.end(), n));
}

#endif
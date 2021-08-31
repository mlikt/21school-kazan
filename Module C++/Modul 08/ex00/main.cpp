#include <iomanip>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <memory>
#include <deque>
#include "easyfind.hpp"

int main (void){

	std::vector<int> l;
	std::vector<int>::iterator it;

	l.insert(l.begin(), 4);
	l.insert(l.begin(), 4);
	l.insert(l.begin(), 4);
	l.insert(l.begin(), 6);
	l.insert(l.begin(), 5);

	it = easyfind(l, 4);

	if (it != l.end())
		std::cout << *it << std::endl;

	std::cout << "------------" << std::endl;

	while(it != l.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	
	std::cout << "------------" << std::endl;

	it = easyfind(l, 0);

	if (it == l.end())
		std::cout << "Not found element" << std::endl;
	return (0);
}
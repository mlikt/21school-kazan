#include <iostream>
#include "mutantstack.hpp"

int main (void){

	MutantStack<int> k;
	MutantStack<int> l;

	k.push(4);
	k.push(3);
	k.push(2);
	k.push(1);

	l = k;	

	l.push(10);
	for (MutantStack<int>::iterator it = k.begin(); it != k.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "--------------" << std::endl;
	for (MutantStack<int>::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "--------------" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "--------------" << std::endl;

	std::cout << mstack.size() << std::endl;
	std::cout << "--------------" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();	
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}

	std::stack<int> s(mstack);
	return (0);
}
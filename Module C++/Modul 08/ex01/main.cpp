#include <iomanip>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <memory>
#include <deque>
#include "span.hpp"


int main (void){

	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::srand(std::time(nullptr));
	std::vector<int> k;


	for(int i = 0; i < 100000; i++)
		k.push_back(std::rand());

	Span s(100000);

	s.addRange(k.begin(), k.end());

	std::cout << s.shortestSpan() << std::endl;
	std::cout << s.longestSpan() << std::endl;

	try
	{
		Span sp(3);
		sp.addNumber(4);
		sp.addNumber(4);
		sp.addNumber(4);
		sp.addNumber(4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Span sp(3);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
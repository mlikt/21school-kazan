#ifndef __SPAN_H__
#define __SPAN_H__
#include <set>
#include <iostream>

class Span
{
private:
	std::multiset<int>	span;
	unsigned int const	N;
public:
	Span();
	Span(unsigned int N);
	~Span() {}
	void addNumber(int const &n);
	int shortestSpan( void ) const;
	int longestSpan( void ) const;

	template <typename Iter>
	void addRange(Iter begin, Iter end){
			span.insert(begin, end);
		if (span.size() > N)
			throw Overflow();
	};

	class Overflow: public std::exception
	{
		public:
		Overflow() {}
		virtual ~Overflow() throw(){}
		virtual const char *what() const throw(){
			return("Overflow Span");
		}
	};

	class SmallRange: public std::exception
	{
		public:
		SmallRange() {}
		virtual ~SmallRange() throw(){}
		virtual const char *what() const throw(){
			return("SmallRange Span");
		}
	};
};

#endif
#include "span.hpp"

Span::Span():N(0){}

Span::Span(unsigned int N): N(N){}

void Span::addNumber(int const &n) {
	span.insert(n);
	if (span.size () > N)
		throw Overflow();
}

int Span::shortestSpan ( void ) const {
	if (span.size() < 2)
		throw SmallRange();

	std::multiset<int>::iterator it = span.begin();
	std::multiset<int>::iterator it1 = ++span.begin();

	int buf;
	int out = *(it1) - *(it);

	while (it1 != span.end())
	{
		if (out == 0)
			return (out);
		buf = *it1 - *it;
		if (std::abs(buf) < std::abs(out))
			out = buf;
		it++;
		it1++;
	}

	return(std::abs(out));
}

int Span::longestSpan ( void ) const {
	if (span.size() < 2)
		throw SmallRange();
	return(std::abs(*(span.rbegin()) -  *(span.begin())));
}

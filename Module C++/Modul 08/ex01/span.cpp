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

	while (true)
	{
		if (out == 0)
			return (out);
		buf = *it1 - *it;
		if (std::abs(buf) < std::abs(out))
			out = buf;
		std::advance(it, 2);
		if (it == span.end())
			break;
		std::advance(it1, 2);
		if (it1 == span.end())
			break ;
	}

	if (N % 2)
	{
		buf = *span.rbegin() - *(++span.rbegin());
		if (std::abs(buf) < std::abs(out))
			out = buf;
	}

	return(std::abs(out));
}

int Span::longestSpan ( void ) const {
	if (span.size() < 2)
		throw SmallRange();
	return(std::abs(*(span.rbegin()) -  *(span.begin())));
}

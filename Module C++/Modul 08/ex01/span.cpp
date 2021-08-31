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
	return(std::abs(*(++span.begin()) -  *(span.begin())));
}

int Span::longestSpan ( void ) const {
	if (span.size() < 2)
		throw SmallRange();
	return(std::abs(*(span.rbegin()) -  *(span.begin())));
}

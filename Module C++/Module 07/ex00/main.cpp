#include "whatever.hpp"
#include <iostream>

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	const char *e = "hello";
	const char *f = "goood";

	swap<const char *>(e,f);
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;


	int b1 = 4;
	double c1 = 3.6;

	std::cout << "b1 = " << b1 << ", c1 = " << c1 << std::endl;
	std::cout << "min( /*int*/ b1, /*double*/ c1) = " << ::min<double>(b1, c1) << " return (double)" << std::endl;

	return (0);
}
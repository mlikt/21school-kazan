#include "header.hpp"

void	print_char (char &c, float &f) {
	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else if (std::isnan(f) || std::isinf(f))
		std::cout << "char: " << "impossible" << std::endl;
	else
		std::cout << "char: " << "Non diplayble" << std::endl;
}

void	print_int (int &i, float &f) {
	if (std::isnan(f) || std::isinf(f))
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void	print_double_and_float (float &f, double &d) {
	if (!(f - static_cast<int>(f)))
		std::cout << std::fixed << std::setprecision(1) 
		<< "float:" << f << "f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (!(d - static_cast<int>(d)))
		std::cout << std::fixed << std::setprecision(1) 
		<< "double:" << d << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

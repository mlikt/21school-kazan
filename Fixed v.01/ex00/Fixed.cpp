#include "Fixed.hpp"

const int Fixed::fraction_bits = 8;

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed()
: number(0)
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = Fixed::fraction_bits;
}

Fixed &Fixed::operator=(Fixed &number)
{
	std::cout << "Assignation operator called" << std::endl;
	this->number = number.number;
	this->_rawBits = number._rawBits;
	return (*this);
}

Fixed::Fixed( Fixed &copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->number);
}

void Fixed::setRawBits(int const _rawBits)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = _rawBits;
}

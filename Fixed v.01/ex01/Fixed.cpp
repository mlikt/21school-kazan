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

Fixed::Fixed( int const &integer )
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = Fixed::fraction_bits;
	this->number = integer << (this->_rawBits);
}

Fixed::Fixed( float const &floating)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = Fixed::fraction_bits;
	this->number = (int)(std::roundf( floating * (float)(1 << this->_rawBits)));
}

Fixed &Fixed::operator=(Fixed const &number)
{
	std::cout << "Assignation operator called" << std::endl;
	this->number = number.number;
	this->_rawBits = number._rawBits;
	return (*this);
}

float Fixed::toFloat( void ) const
{
	float out;
	out = ((float)(this->number) / (float)(1 << this->_rawBits));
	return (out);
}

int Fixed::toInt( void ) const
{
	return (this->number >> this->_rawBits);
}

Fixed::Fixed( Fixed const &copy )
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

std::ostream& operator<<( std::ostream &os, const Fixed &fx )
{
	return os << fx.toFloat();
}

void Fixed::printBinary( void ) const
{
	int i;

	i = 0;
	while(i < 32)
	{
		if (32 - i == this->_rawBits)
			std::cout << ".";
		if ((this->number << i) & 0x80000000)
			std::cout << 1 ;
		else
			std::cout << 0;
		i++;
	}
	std::cout << std::endl;
}
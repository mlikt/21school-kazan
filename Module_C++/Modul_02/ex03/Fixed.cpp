#include "Fixed.hpp"

const int Fixed::_fraction_bits = 8;

Fixed::~Fixed(){}

Fixed::Fixed(): rawBits(0){}

Fixed::Fixed( int const &integer )
{
	this->rawBits = integer << (Fixed::_fraction_bits);
}

Fixed::Fixed( float const &floating)
{
	this->rawBits = (int)(std::roundf(((double)floating * (double)(1 << Fixed::_fraction_bits))));
}

Fixed::Fixed( double const &doublef)
{
	this->rawBits = (int)(std::roundf(((double)doublef * (double)(1 << Fixed::_fraction_bits))));
}

Fixed &Fixed::operator = (Fixed const &number)
{
	this->rawBits = number.rawBits;
	return (*this);
}

Fixed &Fixed::operator = (double const &floating)
{
	this->rawBits = (int)(std::roundf( ((double)floating * (double)Fixed::_fraction_bits)));
	return (*this);
}

Fixed &Fixed::operator = (int const &integer)
{
	this->rawBits = integer << (Fixed::_fraction_bits);
	return (*this);
}

float Fixed::toFloat( void ) const
{
	double out;
	out = ((double)(this->rawBits) / (double)Fixed::_fraction_bits);
	return (out);
}

int Fixed::toInt( void ) const
{
	return (this->rawBits >> Fixed::_fraction_bits);
}

Fixed::Fixed( Fixed const &copy )
{
	*this = copy;
}

int	Fixed::getRawBits( void ) const
{
	return (this->rawBits);
}

void Fixed::setRawBits(int const rawBits)
{
	this->rawBits = rawBits;
}

int Fixed::getFractionBits( void )
{
	return (Fixed::_fraction_bits);
}

std::ostream& operator << ( std::ostream &os, const Fixed &fx )
{
	return (os << (double)(fx.getRawBits()) / (double)(1 << Fixed::getFractionBits()));
}

void Fixed::printBinary( void ) const
{
	int i;

	i = 0;
	while(i < 32)
	{
		if (32 - i == Fixed::getFractionBits())
			std::cout << ".";
		if ((this->rawBits << i) & 0x80000000)
			std::cout << 1 ;
		else
			std::cout << 0;
		i++;
	}
	std::cout << std::endl;
}

bool operator > (Fixed const &number1, Fixed const &number2)
{
	return (number1.getRawBits() > number2.getRawBits());
}

bool operator < (Fixed const &number1, Fixed const &number2)
{
	return (number1.getRawBits() < number2.getRawBits());
}

bool operator == (Fixed const &number1, Fixed const &number2)
{
	return (number2.getRawBits() == number1.getRawBits());
}

bool operator >= (Fixed const &number1, Fixed const &number2)
{
	return (number1.getRawBits() >= number2.getRawBits());
}

bool operator <= (Fixed const &number1, Fixed const &number2)
{
	return (number1.getRawBits() <= number2.getRawBits());
}

bool operator != (Fixed const &number1, Fixed const &number2)
{
	return (number1.getRawBits() != number2.getRawBits());
}

Fixed operator + ( Fixed number1, Fixed number2 )
{
	Fixed out;
	out.setRawBits(number1.getRawBits() + number2.getRawBits());
	return (out);
}

Fixed operator - ( Fixed number1, Fixed number2 )
{
	Fixed out;
	out.setRawBits(number1.getRawBits() - number2.getRawBits());
	return (out);
}

Fixed operator * ( Fixed number1, Fixed number2 )
{
	Fixed out;
	long long int buf;

	buf = (long)number1.getRawBits() * (long)number2.getRawBits();
	out.setRawBits(buf >> Fixed::getFractionBits());
	return (out);
}

Fixed operator / ( Fixed number1, Fixed number2 )
{
	Fixed out;
	long long int buf;

	buf = number1.getRawBits();
	buf = buf << Fixed::getFractionBits();
	buf /= number2.getRawBits();
	out.setRawBits(buf);
	return (out);
}

Fixed &Fixed::operator ++ ( void )
{
	this->rawBits++;
	return (*this);
}

Fixed Fixed::operator ++ ( int )
{
	Fixed out = *this;
	this->rawBits++;
	return (out);
}

Fixed &Fixed::operator -- ( void )
{
	this->rawBits--;
	return (*this);
}

Fixed Fixed::operator -- ( int )
{
	Fixed out = *this;
	this->rawBits--;
	return (out);
}

Fixed Fixed::max(Fixed const &n1, Fixed const &n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

Fixed Fixed::min(Fixed const &n1, Fixed const &n2)
{
	if (n1 <= n2)
		return (n1);
	return (n2);
}

Fixed Fixed::sqrt(Fixed const &fix)
{
	Fixed result = fix;
	Fixed div = fix;
	Fixed fraction;
	if (fix == 0)
		return (0);
	while(true)
	{
		div = (fix / div + div) / 2;
		if (result != div)
			result = div;
		else
			return (result);
	}
}

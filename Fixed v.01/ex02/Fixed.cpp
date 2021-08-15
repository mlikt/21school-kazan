#include "Fixed.hpp"

const int Fixed::fraction_bits = 8;

Fixed::~Fixed()
{
}

Fixed::Fixed()
: number(0)
{
	this->_rawBits = Fixed::fraction_bits;
}

Fixed::Fixed( int const &integer )
{
	this->_rawBits = Fixed::fraction_bits;
	this->number = integer << (this->_rawBits);
}

Fixed::Fixed( float const &floating)
{
	this->_rawBits = Fixed::fraction_bits;
	this->number = (int)(std::roundf( ((double)floating * (double)(1 << this->_rawBits))));
}

Fixed &Fixed::operator = (Fixed const &number)
{
	this->number = number.number;
	this->_rawBits = number._rawBits;
	return (*this);
}

Fixed &Fixed::operator = (float const &floating)
{
	this->number = (int)(std::roundf( ((double)floating * (double)(1 << this->_rawBits))));
	return (*this);
}

Fixed &Fixed::operator = (int const &integer)
{
	this->number = integer << (this->_rawBits);
	return (*this);
}

float Fixed::toFloat( void ) const
{
	double out;
	out = ((double)(this->number) / (double)(1 << this->_rawBits));
	return (out);
}

int Fixed::toInt( void ) const
{
	return (this->number >> this->_rawBits);
}

Fixed::Fixed( Fixed const &copy )
{
	*this = copy;
}

int	Fixed::getRawBits( void ) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const _rawBits)
{
	int step = this->_rawBits - _rawBits;
	if (step < 0)
		this->number = this->number << (-step);
	else if (step > 0)
		this->number = this->number >> (step);
	this->_rawBits = _rawBits;
}

std::ostream& operator << ( std::ostream &os, const Fixed &fx )
{
	return (os << (double)(fx.getNumber()) / (double)(1 << fx.getRawBits()));
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

int Fixed::getFraction( int const _rawBits ) const
{
	int mask;
	int sign;
	int fraction;
	int step = this->_rawBits - _rawBits;

	mask = (1 << this->_rawBits) - 1;
	sign = this->number & 0x80000000;
	if (step < 0)
		fraction = (this->number & mask) << (-step);
	else if (step > 0)
		fraction = (this->number & mask) >> (step);
	else
		fraction = this->number & mask;
	if (sign < 0)
		fraction += (0xFFFFFFFF & ~((1 << _rawBits) - 1));
	return (fraction);
}

int Fixed::getNumber ( void ) const
{
	return (this->number);
}

bool operator > (Fixed const &number1, Fixed const &number2)
{
	int max_rawBits;
	int fraction_n1;
	int fraction_n2;

	if (number1.getRawBits() > number2.getRawBits())
		max_rawBits = number1.getRawBits();
	else
		max_rawBits = number2.getRawBits();
	if ((number1.getNumber() >> number1.getRawBits()) >
		(number2.getNumber() >> number2.getRawBits()))
		return (true);
	if ((number1.getNumber() >> number1.getRawBits()) ==
		(number2.getNumber() >> number2.getRawBits()))
	{
		fraction_n1 = number1.getFraction(max_rawBits);
		fraction_n2 = number2.getFraction(max_rawBits);
		return (fraction_n1 > fraction_n2);
	}
	return (false);
}

bool operator < (Fixed const &number1, Fixed const &number2)
{
	int max_rawBits;
	int fraction_n1;
	int fraction_n2;

	if (number1.getRawBits() < number2.getRawBits())
		max_rawBits = number1.getRawBits();
	else
		max_rawBits = number2.getRawBits();
	if ((number1.getNumber() >> number1.getRawBits()) >
		(number2.getNumber() >> number2.getRawBits()))
		return (true);
	if ((number1.getNumber() >> number1.getRawBits()) ==
		(number2.getNumber() >> number2.getRawBits()))
	{
		fraction_n1 = number1.getFraction(max_rawBits);
		fraction_n2 = number2.getFraction(max_rawBits);
		return (fraction_n1 < fraction_n2);
	}
	return (false);
}

bool operator == (Fixed const &number1, Fixed const &number2)
{
	int max_rawBits;
	int fraction_n1;
	int fraction_n2;

	if (number1.getRawBits() < number2.getRawBits())
		max_rawBits = number1.getRawBits();
	else
		max_rawBits = number2.getRawBits();

	fraction_n1 = number1.getFraction(max_rawBits);
	fraction_n2 = number2.getFraction(max_rawBits);
	if (((number1.getNumber() >> number1.getRawBits())	==
		(number2.getNumber() >> number2.getRawBits()))	&&
		(fraction_n1 == fraction_n2))
		return (true);
	return (false);
}

bool operator >= (Fixed const &number1, Fixed const &number2)
{
	int max_rawBits;
	int fraction_n1;
	int fraction_n2;

	if (number1.getRawBits() > number2.getRawBits())
		max_rawBits = number1.getRawBits();
	else
		max_rawBits = number2.getRawBits();
	if ((number1.getNumber() >> number1.getRawBits()) >
		(number2.getNumber() >> number2.getRawBits()))
		return (true);
	if ((number1.getNumber() >> number1.getRawBits()) ==
		(number2.getNumber() >> number2.getRawBits()))
	{
		fraction_n1 = number1.getFraction(max_rawBits);
		fraction_n2 = number2.getFraction(max_rawBits);
		return (fraction_n1 >= fraction_n2);
	}
	return (false);
}

bool operator <= (Fixed const &number1, Fixed const &number2)
{
	int max_rawBits;
	int fraction_n1;
	int fraction_n2;

	if (number1.getRawBits() > number2.getRawBits())
		max_rawBits = number1.getRawBits();
	else
		max_rawBits = number2.getRawBits();
	if ((number1.getNumber() >> number1.getRawBits()) <
		(number2.getNumber() >> number2.getRawBits()))
		return (true);
	if ((number1.getNumber() >> number1.getRawBits()) ==
		(number2.getNumber() >> number2.getRawBits()))
	{
		fraction_n1 = number1.getFraction(max_rawBits);
		fraction_n2 = number2.getFraction(max_rawBits);
		return (fraction_n1 <= fraction_n2);
	}
	return (false);
}

bool operator != (Fixed const &number1, Fixed const &number2)
{
	int max_rawBits;
	int fraction_n1;
	int fraction_n2;

	if (number1.getRawBits() > number2.getRawBits())
		max_rawBits = number1.getRawBits();
	else
		max_rawBits = number2.getRawBits();
	if ((number1.getNumber() >> number1.getRawBits()) !=
		(number2.getNumber() >> number2.getRawBits()))
		return (true);
	if ((number1.getNumber() >> number1.getRawBits()) ==
		(number2.getNumber() >> number2.getRawBits()))
	{
		fraction_n1 = number1.getFraction(max_rawBits);
		fraction_n2 = number2.getFraction(max_rawBits);
		return (fraction_n1 != fraction_n2);
	}
	return (false);
}

void Fixed::setNumber (int const number)
{
	this->number = number;
}

Fixed operator + ( Fixed number1, Fixed number2 )
{
	Fixed out;
	if (number1.getRawBits() == number2.getRawBits())
	{
		out.setRawBits(number1.getRawBits());
		out.setNumber(number1.getNumber() + number2.getNumber());
		return (out);
	}
	if (number1.getRawBits() < number2.getRawBits())
	{
		number2.setRawBits(number1.getRawBits());
		out.setRawBits(number1.getRawBits());
		out.setNumber(number1.getNumber() + number2.getNumber());
		return (out);
	}
	out.setRawBits(number2.getRawBits());
	number1.setRawBits(number2.getRawBits());
	out.setRawBits(number2.getRawBits());
	out.setNumber(number1.getNumber() + number2.getNumber());
	return (out);
}

Fixed operator - ( Fixed number1, Fixed number2 )
{
	Fixed out;
	if (number1.getRawBits() == number2.getRawBits())
	{
		out.setRawBits(number1.getRawBits());
		out.setNumber(number1.getNumber() - number2.getNumber());
		return (out);
	}
	if (number1.getRawBits() < number2.getRawBits())
	{
		number2.setRawBits(number1.getRawBits());
		out.setRawBits(number1.getRawBits());
		out.setNumber(number1.getNumber() - number2.getNumber());
		return (out);
	}
	out.setRawBits(number2.getRawBits());
	number1.setRawBits(number2.getRawBits());
	out.setRawBits(number2.getRawBits());
	out.setNumber(number1.getNumber() - number2.getNumber());
	return (out);
}

Fixed operator * ( Fixed number1, Fixed number2 )
{
	Fixed out;
	long long int buf;

	if (number1.getRawBits() == number2.getRawBits())
	{
		out.setRawBits(number1.getRawBits());
		buf = (long)number1.getNumber() * (long)number2.getNumber();
		out.setNumber(buf >> out.getRawBits());
		return (out);
	}
	if (number1.getRawBits() < number2.getRawBits())
	{
		number2.setRawBits(number1.getRawBits());
		out.setRawBits(number1.getRawBits());
		buf = (long)number1.getNumber() * (long)number2.getNumber();
		out.setNumber(buf >> out.getRawBits());
		return (out);
	}
	out.setRawBits(number2.getRawBits());
	number1.setRawBits(number2.getRawBits());
	buf = (long)number1.getNumber() * (long)number2.getNumber();
	out.setNumber(buf >> out.getRawBits());
	return (out);
}

Fixed operator / ( Fixed number1, Fixed number2 )
{
	Fixed out;
	long long int buf;
	if (number1.getRawBits() == number2.getRawBits())
	{
		out.setRawBits(number1.getRawBits());
		buf = number1.getNumber();
		buf = buf << number1.getRawBits();
		buf /= number2.getNumber();
		out.setNumber(buf);
		return (out);
	}
	if (number1.getRawBits() < number2.getRawBits())
	{
		number2.setRawBits(number1.getRawBits());
		out.setRawBits(number1.getRawBits());
		buf = number1.getNumber();
		buf = buf << number1.getRawBits();
		buf /= number2.getNumber();
		out.setNumber(buf);
		return (out);
	}
	out.setRawBits(number2.getRawBits());
	number1.setRawBits(number2.getRawBits());
	buf = number1.getNumber();
	buf = buf << number1.getRawBits();
	buf /= number2.getNumber();
	out.setNumber(buf);
	return (out);
}

Fixed &Fixed::operator ++ ( void )
{
	this->number++;
	return (*this);
}

Fixed Fixed::operator ++ ( int )
{
	Fixed out = *this;
	this->number++;
	return (out);
}

Fixed &Fixed::operator -- ( void )
{
	this->number--;
	return (*this);
}

Fixed Fixed::operator -- ( int )
{
	Fixed out = *this;
	this->number++;
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

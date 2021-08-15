
#ifndef __FIXED_H__
# define __FIXED_H__
# include <iostream>
# include <cmath>

class Fixed
{
private:
	static const int	_fraction_bits;
	int					rawBits;
public:
	static Fixed max(Fixed const &n1, Fixed const &n2);
	static Fixed min(Fixed const &n1, Fixed const &n2);
	static int	 getFractionBits( void );
	static Fixed sqrt(Fixed const &fix);
	Fixed();
	Fixed( Fixed	const &copy		);
	Fixed( int		const &integer	);
	Fixed( float	const &floating	);
	Fixed( double	const &doublef	);
	Fixed &operator =  ( Fixed const &number	);
	Fixed &operator =  ( double const &floating	);
	Fixed &operator =  ( int const &integer		);
	Fixed &operator ++ ( void );
	Fixed &operator -- ( void );
	Fixed operator  ++ ( int );
	Fixed operator  -- ( int );
	~Fixed();
	int		getRawBits	( void ) const;
	void	setRawBits	(int const rawBits);
	float	toFloat		( void ) const;
	int		toInt		( void ) const;
	void	printBinary	( void ) const;
};

std::ostream&	operator << ( std::ostream &os, const Fixed &fx );
bool			operator  > (Fixed const &number1, Fixed const &number2);
bool			operator  < (Fixed const &number1, Fixed const &number2);
bool			operator == (Fixed const &number1, Fixed const &number2);
bool			operator >= (Fixed const &number1, Fixed const &number2);
bool			operator <= (Fixed const &number1, Fixed const &number2);
bool			operator != (Fixed const &number1, Fixed const &number2);
Fixed			operator  + ( Fixed number1, Fixed number2 );
Fixed			operator  - ( Fixed number1, Fixed number2 );
Fixed			operator  * ( Fixed number1, Fixed number2 );
Fixed			operator  / ( Fixed number1, Fixed number2 );
#endif
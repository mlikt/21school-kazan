
#ifndef __FIXED_H__
# define __FIXED_H__
# include <iostream>
# include <cmath>

class Fixed
{
private:
	static const int	fraction_bits;
	int					_rawBits;
	int					number;
public:
	static Fixed max(Fixed const &n1, Fixed const &n2);
	static Fixed min(Fixed const &n1, Fixed const &n2);
	Fixed();
	Fixed( Fixed	const &copy		);
	Fixed( int		const &integer	);
	Fixed( float	const &floating	);
	Fixed &operator =  ( Fixed const &number	);
	Fixed &operator =  ( float const &floating	);
	Fixed &operator =  ( int const &integer		);
	Fixed &operator ++ ( void );
	Fixed &operator -- ( void );
	Fixed operator  ++ ( int );
	Fixed operator  -- ( int );
	~Fixed();
	int		getNumber	( void ) const;
	void	setNumber	( int const number );
	int		getRawBits	( void ) const;
	void	setRawBits	(int const _rawBits);
	float	toFloat		( void ) const;
	int		toInt		( void ) const;
	void	printBinary	( void ) const;
	int		getFraction	( int const _rawBits ) const;
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

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
	Fixed();
	Fixed( Fixed	const &copy		);
	Fixed( int		const &integer	);
	Fixed( float	const &floating	);
	Fixed &operator =  ( Fixed const &number );
	~Fixed();
	int		getRawBits	( void ) const;
	void	setRawBits	(int const _rawBits);
	float	toFloat		( void ) const;
	int		toInt		( void ) const;
	void	printBinary	( void ) const;
};

std::ostream&	operator<<( std::ostream &os, const Fixed &fx );
#endif
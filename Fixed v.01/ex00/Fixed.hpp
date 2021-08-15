
#ifndef __FIXED_H__
# define __FIXED_H__
# include <iostream>

class Fixed
{
private:
	static const int	fraction_bits;
	int					_rawBits;
	int					number;
public:
	Fixed();
	Fixed(Fixed &copy);
	Fixed &operator = ( Fixed &number );
	~Fixed();
	int		getRawBits ( void ) const;
	void	setRawBits (int const _rawBits);
};


#endif
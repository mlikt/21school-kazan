
#ifndef __FIXED_H__
# define __FIXED_H__
# include <iostream>

class Fixed
{
private:
	static const int	_fraction_bits;
	int					rawBits;
public:
	Fixed();
	Fixed(Fixed &copy);
	Fixed &operator = ( Fixed &rawBits );
	~Fixed();
	int		getRawBits ( void ) const;
	void	setRawBits (int const rawBits);
};


#endif
#ifndef __KAREN_H__
#define __KAREN_H__
#include <iostream>
#include <string>

class Karen
{
private:
	void	debug	( void );
	void	info	( void );
	void	warning	( void );
	void	error	( void );
	void	(Karen::*complaints[4])( void );
public:
	Karen();
	void complain(std::string level);
	~Karen() {}
};
#endif
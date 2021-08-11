#include "Karen.hpp"

void Karen::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
	<< " I just love it!\n" 
	<< std::endl;
}

void Karen::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout <<  "I cannot believe adding extra bacon cost more money.\n"
	<< "You don’t put enough! If you did I would not have to ask for it!\n" 
	<< std::endl;
}

void Karen::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. \n"
	<< "I’ve been coming here for years and you just started working"
	<< " here last month.\n"
	<< std::endl;
}

void Karen::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout
	<< "This is unacceptable, I want to speak to the manager now.\n"
	<< std::endl;
}

Karen::Karen()
{
	complaints[0] = &Karen::debug;
	complaints[1] = &Karen::info;
	complaints[2] = &Karen::warning;
	complaints[3] = &Karen::error;
}

void Karen::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	
	for(i = 0; i < 4; ++i)
	{
		if (level == levels[i])
			break;
	}

	switch (i)
	{
	case (0):
		(this->*(complaints[0]))();
	case (1):
		(this->*(complaints[1]))();
	case (2):
		(this->*(complaints[2]))();
	case (3):
		(this->*(complaints[3]))();
		break;
	default:
		std::cout << "Unknown complaint." << std::endl;
		break;
	}
}

#include "Karen.hpp"

int main(int argc, char **argv)
{
	std::string  complain;

	if (argc == 2)
	{
		complain = argv[1];
		Karen SweetKaren;
		SweetKaren.complain(complain);
	}
	else
	{
		std::cout 
		<< "Karen, please tell me what the problem is in one argument."
		<< std::endl;
	}
	return (0);
}
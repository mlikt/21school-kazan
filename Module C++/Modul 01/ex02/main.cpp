#include <iostream>
#include <string>

int main( void )
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR;
	std::string &stringREF = str;

	stringPTR = &str;
	std::cout << &str		<< std::endl;
	std::cout << &stringREF	<< std::endl;
	std::cout << stringPTR	<< std::endl;
	return (0);
}
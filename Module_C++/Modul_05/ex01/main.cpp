#include "Bureaucrat.hpp"
#include "Form.hpp"



int main ( void ){

	std::cout << "-----------------------" << std::endl;
	/* Слишком высокие оценки Form */
	try
	{
		// std::cout << "Code that will fail" << std::endl;
		Form home("HomeForm", 33, -1);
		std::cout << "Code that will fail" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form home("HomeForm", -33, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form home("HomeForm", -33, 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------------------" << std::endl;
	/* Слишком низкие оценки Form */

	try
	{
		Form home("HomeForm", 1344, 155);
		std::cout << "Code that will fail" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form home("HomeForm", 33, 211);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form home("HomeForm", 655, 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------------------" << std::endl;
	/* Отсуствие достаточного балла (квалификации) */

	try
	{
		Bureaucrat Bob("Bob", 145);
		Form home("HomeForm", 66, 33);
		home.beSigned(Bob);
		std::cout << "Code that will fail" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------------------" << std::endl;

	/* Успешно подписанный документ */
	try
	{
		Bureaucrat Bob("Bob", 15);
		Form home("HomeForm", 66, 33);
		std::cout << home << std::endl;
		home.beSigned(Bob);
		std::cout << home << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------------------" << std::endl;

	// Form home("HomeForm", 33, -1); // Для проверки какой обработчик вызывается
	// Form home("HomeForm", 66, 33);
	return (0);
}
#include "Bureaucrat.hpp"

int main ( void ){
	try
	{
		Bureaucrat Bob("Bob", 24);
		std::cout << Bob << std::endl;
		Bureaucrat Bim("Bim", 156);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Bim("Bim", -1);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Bob("Bob", 1);
		Bob.increaseGrade();
		std::cout << Bob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Bob("Bob", 150);
		Bob.downGrade();
		std::cout << Bob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		// std::cerr << e.getName() << std::endl;	// Чтобы выполнился этот метод,
													// нужно отлавливать наследника
													// std::exeption
	}
	
	// try
	// {
	Bureaucrat Bob("Bob", 151); // Что будет если не обрабатывать исключение? 
								// Программа должна завершиться abort()
								// и вывести название и пространство имен обработчика. 
	// }
	// catch(...)				// Для отловки любого обработчика, при этом программа не завершается.
	// {
	// 		std::cout << "В блоке try, что-то пошло не так" << std::endl;
	// }
	// Bureaucrat Bob("Bob", -1);

	std::cout << "Code that will fail" << std::endl;
	return (0);
}
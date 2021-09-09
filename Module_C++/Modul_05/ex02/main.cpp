#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"
#include "include/PresidentiaPardonForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/ShrubberyCreationForm.hpp"

#define LINE std::cout << "------------------------------" << std::endl;

int main ( void ){

	// Отсутствие подписи!
	try
	{
		LINE
		Bureaucrat Bob("Bob", 3);
		Bureaucrat Crist("Crist", 20);
		PresidentiaPardonForm form("K");
		Bob.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// Недостаточно баллов для исполнения!!!
	try
	{
		LINE
		Bureaucrat Bob("Bob", 3);
		Bureaucrat Crist("Crist", 20);
		PresidentiaPardonForm form("K");
		form.beSigned(Crist);
		LINE
		Crist.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// Роботизируем!!!
	try
	{
		LINE
		Bureaucrat Bob("Bob", 3);
		Bureaucrat Crist("Crist", 20);
		RobotomyRequestForm form("Bureaucratic Machine");
		form.beSigned(Crist);
		LINE //Mожет получиться, а может не получиться ПИСЯТНАПИСЯТКОРОЧЕ
		Crist.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// А можно посадить дерево?
	try
	{
		LINE
		Bureaucrat Bob("Bob", 3);
		Bureaucrat Crist("Crist", 20);
		ShrubberyCreationForm form("MyTree");
		form.beSigned(Crist);
		LINE // Посмотри создался ли файл MyTree_shrebbery? Загляни внутрь файла.
		Crist.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
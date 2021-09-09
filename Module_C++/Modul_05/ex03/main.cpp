#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"
#include "include/PresidentiaPardonForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/Intern.hpp"

#define LINE std::cout << "------------------------------" << std::endl;

int main ( void ) {

	Intern someRandomIntern;
	Form* rrf;
	Bureaucrat Born("Born", 1);
	LINE
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf->beSigned(Born);
	Born.executeForm(*rrf);

	delete rrf;
	LINE
	rrf = someRandomIntern.makeForm("tl;dr", "tl;dr");
	delete rrf;
	LINE
	rrf = someRandomIntern.makeForm("presidentia pardon", "Terminator");
	rrf->beSigned(Born);
	Born.executeForm(*rrf);
	delete rrf;
	LINE
	rrf = someRandomIntern.makeForm("shrubbery creation", "NewTree");
	rrf->beSigned(Born);
	Born.executeForm(*rrf);
	delete rrf;
	LINE
	return (0);
}
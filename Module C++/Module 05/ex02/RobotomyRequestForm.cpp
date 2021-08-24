#include "include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: Form("robotomy request", 72, 45), target("Unknow target")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
: Form("robotomy request", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
: Form(copy), target(copy.target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &source)
{
	const_cast<std::string &>(this->name_form) = source.name_form;
	const_cast<std::string &>(this->target) = source.target;
	const_cast<int &>(this->grade_sign) = source.grade_sign;
	const_cast<int &>(this->grade_exec) = source.grade_exec;
	this->sign = source.sign;
	return (*this);
}

void RobotomyRequestForm::execute ( Bureaucrat const &executer ) const {
	if (!(this->sign))
		throw Form::NoSignature(*this, this->target);
	if (executer.getGrade() > this->grade_exec)
		throw Form::GradeTooLowException(*this, executer, true);
	std::cout << '\a' << std::flush;
	std::srand(std::time(nullptr));
	if (std::rand() % 2)
		std::cout << this->target + " has been robotomized successfully." << std::endl;
	else
		std::cout << this->target + " has been NOT robotic successfully" << std::endl;
}
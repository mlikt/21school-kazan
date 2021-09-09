#include "include/PresidentiaPardonForm.hpp"

PresidentiaPardonForm::PresidentiaPardonForm()
: Form("presidentia pardon", 25, 5), target("Unknow target")
{}

PresidentiaPardonForm::PresidentiaPardonForm(std::string const &target)
: Form("presidentia pardon", 25, 5), target(target)
{}

PresidentiaPardonForm::PresidentiaPardonForm(PresidentiaPardonForm const &copy)
: Form(copy), target(copy.target)
{}

PresidentiaPardonForm& PresidentiaPardonForm::operator=(PresidentiaPardonForm const &source)
{
	const_cast<std::string &>(this->name_form) = source.name_form;
	const_cast<std::string &>(this->target) = source.target;
	const_cast<int &>(this->grade_sign) = source.grade_sign;
	const_cast<int &>(this->grade_exec) = source.grade_exec;
	this->sign = source.sign;
	return (*this);
}

void PresidentiaPardonForm::execute ( Bureaucrat const &executer ) const{
	if (!(this->sign))
		throw Form::NoSignature(*this, this->target);
	if (executer.getGrade() > this->grade_exec)
		throw Form::GradeTooLowException(*this, executer, true);
	std::cout <<  this->target << " has been pardoned by Zafod Beeblebrox." 
	<< std::endl;
}
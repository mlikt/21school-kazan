#include "include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: Form("shrubbery creation", 145, 137), target("Unknow target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
: Form("shrubbery creation", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
: Form(copy), target(copy.target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &source)
{
	const_cast<std::string &>(this->name_form) = source.name_form;
	const_cast<std::string &>(this->target) = source.target;
	const_cast<int &>(this->grade_sign) = source.grade_sign;
	const_cast<int &>(this->grade_exec) = source.grade_exec;
	this->sign = source.sign;
	return (*this);
}

void ShrubberyCreationForm::execute ( Bureaucrat const &executer ) const {
	Tree tree;

	if (!(this->sign))
		throw Form::NoSignature(*this, this->target);
	if (executer.getGrade() > this->grade_exec)
		throw Form::GradeTooLowException(*this, executer, true);
	std::ofstream out_file;
	out_file.open(this->target + "_shrubbery");
	out_file << tree.getTree();
	out_file.close();
}

Form* ShrubberyCreationForm::createDublicate	( std::string const &target){
	return (new ShrubberyCreationForm(target));
}
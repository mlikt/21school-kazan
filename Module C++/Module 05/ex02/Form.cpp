#include "include/Form.hpp"

/* Описание методов класса Form */

Form::Form()
:name_form("Unknow form"), sign(false),
grade_sign(150), grade_exec(150)
{}

Form::Form(std::string const &name, int const &grade_sign, int const &grade_exec)
: name_form(name), sign(false), grade_sign(grade_sign), grade_exec(grade_exec)
{
	/* Бросаем исключения */
	if (this->grade_exec <= 0)
		throw GradeTooHighException(*this);
	if (this->grade_sign <= 0)
		throw GradeTooHighException(*this);
	if ( this->grade_exec > 150)
		throw GradeTooLowException(*this);
	if (this->grade_sign > 150)
		throw GradeTooLowException(*this);
}

Form::Form(Form const &copy)
: name_form(copy.name_form), sign(copy.sign),
grade_sign(copy.grade_sign), grade_exec(copy.grade_exec)
{}

Form& Form::operator=(Form const &source)
{
	const_cast<std::string &>(this->name_form) = source.name_form;
	const_cast<int &>(this->grade_sign) = source.grade_sign;
	const_cast<int &>(this->grade_exec) = source.grade_exec;
	this->sign = source.sign;
	return (*this);
}

std::string Form::getNameForm ( void ) const {
	return (this->name_form);
}

bool Form::getSign ( void ) const {
	return (this->sign);
}

int Form::getGradeSign ( void ) const {
	return (this->grade_sign);
} 

int Form::getGradeExec ( void ) const {
	return (this->grade_exec);
}

void Form::beSigned ( Bureaucrat const &br ) {
	/* Бросаем исключения */
	if (br.getGrade() > this->grade_sign)
		throw GradeTooLowException(*this, br);
	this->sign = true;
	std::cout << br.getName() << " signs " << this->name_form << std::endl;
}

/* Конец описания методов класса Form */

/* Описание методов класса Form::GradeTooHighException (обработчик)*/

Form::GradeTooHighException::GradeTooHighException(Form const &example)
:example(&example), br(nullptr)
{}

Form::GradeTooHighException::GradeTooHighException(Form const &example, Bureaucrat const &br)
:example(&example), br(&br)
{}

const char *Form::GradeTooHighException::what() const throw(){
	std::string out;

	out = "Form " + this->example->name_form + " got an unacceptably high";
	if (this->example->grade_sign <= 0)
		out = out + " grade sign: " + std::to_string(this->example->grade_sign);
	if (this->example->grade_exec <= 0)
	{
		if (this->example->grade_sign <= 0)
			out = out + " and";
		out = out + " grade execute: " + std::to_string(this->example->grade_exec);
	}
	return (out.c_str());
}

/* Конец описания методов класса Form::GradeTooHighException */

/* Описание методов класса Form::GradeTooLowException (обработчик) */

Form::GradeTooLowException::GradeTooLowException(Form const &example)
:example(&example), br(nullptr), execute(false)
{}

Form::GradeTooLowException::GradeTooLowException(Form const &example, Bureaucrat const &br)
:example(&example), br(&br), execute(false)
{}

Form::GradeTooLowException::GradeTooLowException(Form const &example, Bureaucrat const &br, bool const &execute)
:example(&example), br(&br), execute(execute)
{}

const char *Form::GradeTooLowException::what() const throw(){
	std::string out;

	if (!(this->br))
	{
		out = "Form " + this->example->name_form + " got an unacceptably low";
		if (this->example->grade_sign > 150)
			out = out + " grade sign: " + std::to_string(this->example->grade_sign);
		if (this->example->grade_exec > 150)
		{
			if (this->example->grade_sign > 150)
				out = out + " and";
			out = out + " grade execute: " + std::to_string(this->example->grade_exec);
		}
		return (out.c_str());
	}
	if (!(this->execute))
	out = this->br->getName() + " cannot sign " + this->example->name_form
	+ " because, he does not have the appropriate qualifications.\n"
	+ "Bob's qualifications(grade): " + std::to_string(this->br->getGrade())
	+ "\nForm grade sign: " + std::to_string(this->example->grade_sign);
	if (this->execute)
	out = this->br->getName() + " cannot execute " + this->example->name_form
	+ " because, he does not have the appropriate qualifications.\n"
	+ "Bob's qualifications(grade): " + std::to_string(this->br->getGrade())
	+ "\nForm grade execute: " + std::to_string(this->example->grade_exec);
	return (out.c_str());
}

/* Конец описания методов класса Form::GradeTooLowException */

/* Описание методов класса Form::NoSignature (обработчик) */

Form::NoSignature::NoSignature(Form const &example, std::string const &target)
: example(&example), target(&target)
{}

const char *Form::NoSignature::what() const throw() {
	std::string out;
	out = "Forgiveness for the target of " + *(this->target) + 
	" cannot be fulfilled because the " + 
	this->example->name_form + " form has not been signed.";
	return (out.c_str());
}
/* Конец описания методов класса Form::NoSignature */

/* Перегрузка оператора вывода в поток данных */

std::ostream&	operator << ( std::ostream &os, const Form &example ){
	os << "Name form: "		<< example.getNameForm()
	<< " , Grade sign: "	<< example.getGradeSign()
	<< " , Grade execute: "	<< example.getGradeExec()
	<< " , Sign state: "	<< example.getSign();
	return (os);
}
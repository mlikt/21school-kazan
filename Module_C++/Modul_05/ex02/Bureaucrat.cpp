#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"

Bureaucrat::Bureaucrat() :name("Unknow bureacrat"), ranges(150)
{}

Bureaucrat::Bureaucrat( std::string const &name, const int &ranges)
:name(name), ranges(ranges) {
	if (this->ranges > 150)
		throw GradeTooLowException(this->ranges, this->name);
	if (this->ranges <= 0)
		throw GradeTooHighException(this->ranges, this->name);
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): name(copy.name), ranges(copy.ranges)
{}

Bureaucrat &Bureaucrat::operator = (Bureaucrat const &source)
{
	const_cast<std::string &>(this->name) = source.name;
	this->ranges = source.ranges;
	return (*this);
}

std::string Bureaucrat::getName( void ) const {
	return (this->name);
}

int Bureaucrat::getGrade ( void ) const {
	return (this->ranges);
}

void Bureaucrat::increaseGrade( void ){
	this->ranges--;
	if (this->ranges <= 0)
		throw GradeTooHighException(this->ranges, this->name);
}

void Bureaucrat::downGrade ( void ){
	this->ranges++;
	if (this->ranges > 150)
		throw GradeTooLowException(this->ranges, this->name);
}

void Bureaucrat::executeForm (Form const & form){
	form.execute(*this);
	std::cout << this->name << " executes " << form.getNameForm() << std::endl;
}

/* Функции обработчиков */

Bureaucrat::GradeTooHighException::GradeTooHighException(const int &ranges, std::string const &name )
:ranges(ranges), name(name) { CreateMsg(); }


Bureaucrat::GradeTooLowException::GradeTooLowException(const int &ranges, std::string const &name)
: ranges(ranges), name(name){ CreateMsg(); }

void Bureaucrat::GradeTooLowException::CreateMsg(){
	out = this->name + " got an unacceptably low grade: " + std::to_string(this->ranges);
}

void Bureaucrat::GradeTooHighException::CreateMsg(){
	out = this->name + " got an unacceptably high grade: " + std::to_string(this->ranges);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (out.c_str());
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (out.c_str());
}

std::string Bureaucrat::GradeTooLowException::getName( void ) const {
	return (this->name);
}

int Bureaucrat::GradeTooLowException::getGrade ( void ) const {
	return (this->ranges);
}

std::string Bureaucrat::GradeTooHighException::getName( void ) const {
	return (this->name);
}

int Bureaucrat::GradeTooHighException::getGrade ( void ) const {
	return (this->ranges);
}

/* Перегрузка оператора вывода в поток */

std::ostream&	operator << ( std::ostream &os, const Bureaucrat &br ){
	os << br.getName() << " bureaucrat grade " << br.getGrade();
	return (os);
}
#ifndef __FORM_H__
#define __FORM_H__
#include "Bureaucrat.hpp"

class Form
{
private:
	std::string const name_form;
	bool		sign;
	int const	grade_sign;
	int const	grade_exec;
public:
	Form();
	Form(std::string const &name, int const &grade_sign, int const &grade_exec);
	Form(Form const &copy);
	Form& operator = (Form const &source);
	~Form() {}
	std::string getNameForm		( void ) const;
	bool		getSign			( void ) const;
	int			getGradeSign	( void ) const;
	int			getGradeExec	( void ) const;
	void		beSigned		( Bureaucrat const &br );

	class GradeTooHighException: public std::exception
	{
	private:
		Form		const	*example;
		Bureaucrat	const	*br;
	public:
		GradeTooHighException(Form const &example);
		GradeTooHighException(Form const &example, Bureaucrat const &br);
		virtual const char* what() const throw();
		virtual ~GradeTooHighException() throw() {}
	};

	class GradeTooLowException: public std::exception
	{
	private:
		Form		const	*example;
		Bureaucrat	const	*br;
	public:
		GradeTooLowException(Form const &example);
		GradeTooLowException(Form const &example, Bureaucrat const &br);
		virtual const char *what() const throw();
		virtual ~GradeTooLowException() throw() {}
	};
};

std::ostream&	operator << ( std::ostream &os, const Form &example );
#endif
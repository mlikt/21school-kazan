#ifndef __FORM_H__
#define __FORM_H__
#include "Bureaucrat.hpp"

class Form
{
protected:
	std::string const name_form;
	bool		sign;
	int const	grade_sign;
	int const	grade_exec;
public:
	Form();
	Form(std::string const &name, int const &grade_sign, int const &grade_exec);
	Form(Form const &copy);
	Form& operator = (Form const &source);
	virtual ~Form() {}
	std::string  getNameForm	( void ) const;
	bool		 getSign		( void ) const;
	int			 getGradeSign	( void ) const;
	int			 getGradeExec	( void ) const;
	void		 beSigned		( Bureaucrat const &br );
	virtual void execute		( Bureaucrat const &executer ) const = 0;

	class GradeTooHighException: public std::exception
	{
	private:
		Form		const	*example;
		Bureaucrat	const	*br;
		std::string			out;
	public:
		GradeTooHighException(Form const &example);
		GradeTooHighException(Form const &example, Bureaucrat const &br);
		void CreateMsg();
		virtual const char* what() const throw();
		virtual ~GradeTooHighException() throw() {}
	};

	class GradeTooLowException: public std::exception
	{
	private:
		Form		const	*example;
		Bureaucrat	const	*br;
		bool				execute;
		std::string			out;
	public:
		GradeTooLowException(Form const &example);
		GradeTooLowException(Form const &example, Bureaucrat const &br);
		GradeTooLowException(Form const &example, Bureaucrat const &br, bool const &execute);
		void CreateMsg();
		virtual const char *what() const throw();
		virtual ~GradeTooLowException() throw() {}
	};

	class NoSignature: public std::exception
	{
	private:
		Form		const	*example;
		std::string const	*target;
		std::string			out;
	public:
		NoSignature(Form const &example, std::string const &target);
		void CreateMsg();
		virtual const char *what() const throw();
		virtual ~NoSignature() throw() {}
	};
};

std::ostream&	operator << ( std::ostream &os, const Form &example );
#endif
#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__
#include <iostream>
#include <string>

class Bureaucrat
{
private:
	std::string const	name;
	int					ranges;
public:
	Bureaucrat ();
	Bureaucrat(std::string const &name, const int &ranges);
	Bureaucrat(Bureaucrat const &copy);
	Bureaucrat &operator=(Bureaucrat const &source);
	~Bureaucrat() {}
	std::string	getName			( void ) const;
	int			getGrade		( void ) const;
	void		increaseGrade	( void );
	void		downGrade		( void );

	class GradeTooHighException: public std::exception
	{
		private:
			int	ranges;
			std::string const name;
		public:
			GradeTooHighException(const int &ranges, std::string const &name);
			int			getGrade		( void ) const;
			std::string	getName			( void ) const;
			virtual const char*	what() const throw();
			virtual ~GradeTooHighException() throw() {}
	};

	class GradeTooLowException: public std::exception
	{
		private:
			int ranges;
			std::string const name;
		public:
			GradeTooLowException(const int &ranges, std::string const &name);
			int			getGrade		( void ) const;
			std::string	getName			( void ) const;
			virtual const char*	what() const throw();
			virtual ~GradeTooLowException() throw() {}
	};
};

std::ostream&	operator << ( std::ostream &os, const Bureaucrat &br );
#endif

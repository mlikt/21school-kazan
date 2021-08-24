#ifndef __ROBOTOMYREQUESTFORM_H__
#define __ROBOTOMYREQUESTFORM_H__
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
private:
	std::string const target;
public:
	RobotomyRequestForm ();
	RobotomyRequestForm (std::string const &target);
	RobotomyRequestForm (RobotomyRequestForm const &copy);
	RobotomyRequestForm& operator=(RobotomyRequestForm const &source);

	virtual Form* createDublicate	( std::string const &target);
	virtual void  execute 			( Bureaucrat const &executer ) const;

	virtual ~RobotomyRequestForm() {}
};

#endif
#ifndef __PRESIDENTIAPARDONFORM_H__
#define __PRESIDENTIAPARDONFORM_H__
#include "Form.hpp"

class PresidentiaPardonForm: public Form
{
private:
	std::string const target;
public:
	PresidentiaPardonForm ();
	PresidentiaPardonForm (std::string const &target);
	PresidentiaPardonForm (PresidentiaPardonForm const &copy);
	PresidentiaPardonForm& operator=(PresidentiaPardonForm const &source);
	virtual void execute ( Bureaucrat const &executer ) const;
	virtual ~PresidentiaPardonForm() {}
};

#endif
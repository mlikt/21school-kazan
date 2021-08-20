#ifndef __BRAIN_H__
#define __BRAIN_H__
#include <string>
#include <iostream>

class Brain
{
private:
	std::string idea[100];
public:
	Brain();
	Brain(Brain &);
	Brain &operator = (Brain &);
	~Brain();
};

#endif

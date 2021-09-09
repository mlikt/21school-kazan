#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include <iostream>
#include <iomanip>
#include <string>
#define EXIT		0
#define ADD			1
#define SEARCH		2
#define NOTFOUND	3

class Contact
{
public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darckes_secret;
};

class PhoneBook
{
private:
	int			count;
	int			next;
	int			index;
	std::string	comand;
	Contact		contact[8];
public:
	PhoneBook();
	~PhoneBook();
	int		ReadComand(void);
	void	Header(void);
	void	ListContacts(void);
	void	InfoContact(void);
	void	AdditonСontact(void);
	void	ReWrite(Contact *buf, int index);
	void	SearchContact(void);
};

#endif
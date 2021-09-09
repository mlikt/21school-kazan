#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->count = 0;
	this->index = 0;
}

PhoneBook::~PhoneBook()
{
	int i;

	i = 0;
	while(i < this->count)
	{
		std::cout << "index[" << i <<"] remove contact" << std::endl;
		i++;
	}
}

void PhoneBook::Header(void)
{
	if (this->count == 0)
	{
		std::cout << "The phone book is empty." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << std::right << "index";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "first name";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "last name";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "nickname";
	std::cout << std::endl;
}

void PhoneBook::ReWrite(Contact *buf, int index)
{
	if (buf->first_name.size()		||
		buf->last_name.size()		||
		buf->nickname.size()		||
		buf->phone_number.size()	||
		buf->darckes_secret.size()
		)
	{
		if (this->count < 8)
			this->count++;
		this->contact[index].first_name = buf->first_name;
		this->contact[index].last_name = buf->last_name;
		this->contact[index].nickname = buf->nickname;
		this->contact[index].phone_number = buf->phone_number;
		this->contact[index].darckes_secret = buf->darckes_secret;
		this->next++;
	}
}

void PhoneBook::AdditonСontact( void )
{
	int index;
	Contact buf;
	if(!((this->next + 1) % 9))
		this->next = 0;
	index = this->next;
	std::cout << "First name    : " << std::flush;
	std::getline(std::cin, buf.first_name);
	if (std::cin.eof())
		return ;
	std::cout << "Last name     : " << std::flush;
	std::getline(std::cin, buf.last_name);
	if (std::cin.eof())
		return ;
	std::cout << "Nickname      : " << std::flush;
	std::getline(std::cin, buf.nickname);
	if (std::cin.eof())
		return ;
	std::cout << "Phone number  : " << std::flush;
	std::getline(std::cin, buf.phone_number);
	if (std::cin.eof())
		return ;
	std::cout << "Darkest secret: " << std::flush;
	std::getline(std::cin, buf.darckes_secret);
	if (std::cin.eof())
		return ;
	this->ReWrite(&buf, index);
}

int	PhoneBook::ReadComand(void)
{
	if(!std::cin.eof())
		std::cout << "> " << std::flush;
	std::getline(std::cin, this->comand);
	if (std::cin.eof())
		return(EOF);
	else if(!this->comand.find("EXIT"))
	{
		std::cin.clear();
		return (EXIT);
	}
	else if(!this->comand.find("ADD"))
	{
		std::cin.clear();
		return (ADD);
	}
	else if(!this->comand.find("SEARCH"))
	{
		std::cin.clear();
		return (SEARCH);
	}
	else
	{
		std::cin.clear();
		return (NOTFOUND);
	}
	return (EOF);
}

void PhoneBook::ListContacts(void)
{
	int i;

	i = 0;
	while(i < this->count)
	{
		std::cout << std::setw(10) << i << std::flush << "|" << std::flush;
		if (this->contact[i].first_name.size() <= 10)
			std::cout			<< std::setw(10)	
			<< std::right		<< this->contact[i].first_name 
			<< std::flush		<< "|" << std::flush;
		else
			std::cout 
			<< std::setw(10) 									<< std::right 
			<<this->contact[i].first_name.substr(0, 9) + '.'	<< std::flush 
			<< "|"												<< std::flush;
		if (this->contact[i].last_name.size() <= 10)
			std::cout			<< std::right
			<< std::setw(10)	<< this->contact[i].last_name 
			<< std::flush		<< "|" << std::flush;
		else
			std::cout 
			<< std::setw(10)									<< std::right
			<< this->contact[i].last_name.substr(0, 9) + '.'	<< std::flush 
			<< "|"												<< std::flush;
		if (this->contact[i].nickname.size() <= 10)
			std::cout			<< std::right
			<< std::setw(10)	<< this->contact[i].nickname
			<< std::flush;
		else
			std::cout			<< std::right
			<< std::setw(10)	<< this->contact[i].nickname.substr(0, 9) + '.'
			<< std::flush;
		std::cout << std::endl;
		i++;
	}
}

void PhoneBook::InfoContact(void)
{
	if (!this->count)
		return ;
	std::cout << "Input index > ";
	if((std::cin >>  std::noskipws >> this->index
		&& this->index < this->count && std::cin.get() == 10 ))
	{

			std::cout << "First name    : " << this->contact[this->index].first_name		<< std::endl;
			std::cout << "Last name     : " << this->contact[this->index].last_name			<< std::endl;
			std::cout << "Nickname      : " << this->contact[this->index].nickname			<< std::endl;
			std::cout << "Phone number  : " << this->contact[this->index].phone_number		<< std::endl;
			std::cout << "Darkest secret: " << this->contact[this->index].darckes_secret	<< std::endl;
	}
	else
	{
		if(std::cin.eof())
			return ;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Incorrect index" << std::endl;
	}

}

void PhoneBook::SearchContact(void)
{

	this->Header();
	this->ListContacts();
	this->InfoContact();
}

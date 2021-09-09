#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	MyPhoneBook;
	int			comand;

	while(1)
	{
		comand = MyPhoneBook.ReadComand();
		if(comand == EXIT || comand == EOF)
			break;
		else if(comand == ADD)
			MyPhoneBook.AdditonСontact();
		else if(comand == SEARCH)
			MyPhoneBook.SearchContact();
	};
	return (0);
}
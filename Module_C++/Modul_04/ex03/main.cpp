#include "include/AMateria.hpp"
#include "include/ICharacter.hpp"
#include "include/Character.hpp"
#include "include/MateriaSource.hpp"
#include "include/Ice.hpp"
#include "include/Cure.hpp"

//Color

#define RED		"\x1b[31m"
#define BLUE	"\x1b[34m"
#define YELLOW	"\x1b[33m"
#define GREEN	"\x1b[32m"
#define MAGENTA	"\x1b[35m"
#define END		"\x1b[0m"


int main ( void )
{
	std::string str;
	std::cout << RED "---------------------" << std::endl;
	IMateriaSource *src = new MateriaSource();

	std::cout << "---------------------" << std::endl;
	src->learnMateria(new Ice());
	std::cout << "---------------------" << std::endl;
	src->learnMateria(new Cure());
	std::cout << "---------------------" << std::endl;
	src->learnMateria(new Cure());
	std::cout << "---------------------" << std::endl;
	src->learnMateria(new Cure());
	std::cout << "!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	src->learnMateria(new Cure());
	std::cout << "---------------------" END YELLOW << std::endl;


	AMateria *ptr = src->createMateria("ice");
	std::cout << "---------------------" END GREEN << std::endl;

	ICharacter *Bob = new Character("Bob");
	ICharacter *Bim = new Character("Bim");

	std::cout << "---------------------" END BLUE<< std::endl;
	Bob->equip(ptr);
	std::cout << END YELLOW "---------------------" << std::endl;
	ptr = src->createMateria("bumerang");
	std::cout << ptr << std::endl;
	std::cout << "---------------------" << std::endl;
	ptr = src->createMateria("cure");
	std::cout << "---------------------" END MAGENTA << std::endl;
	Bob->equip(ptr);
	std::cout << END "---------------------" BLUE << std::endl;
	Bob->use(0,*Bim);
	std::cout << END "---------------------" YELLOW << std::endl;
	Bob->unequip(1);
	std::cout << "---------------------" << std::endl;
	Bim->equip(ptr);
	std::cout << "---------------------" << std::endl;
	for(int i = 0; i < 5; i++)
	{
		ptr = src->createMateria("cure");
		Bob->equip(ptr);
	}
	std::cout << END MAGENTA "---------------------" << std::endl;
	Bim->use(0, *Bob);
	std::cout << END RED "---------------------" << std::endl;
	delete src;
	std::cout << "---------------------" << std::endl;
	delete Bob;
	std::cout << "---------------------" << std::endl;
	delete Bim;
	std::cout << "---------------------" << std::endl;
	delete ptr;
	std::cout << "---------------------" END << std::endl;
	std::getline(std::cin, str); // Придержим исполнение программы, чтобы проверить существуют ли утечки?

	return (0);
}
#include "Array.hpp"
#include <string>

#define LINE std::cout << "------------------------------" << std::endl;

int main ( void ){

	Array<int> b(4);
	Array<int> a;
	Array<std::string> strings(5);
	LINE
	std::cout << "Проверка есть ли мусорные значения?" << std::endl;
	LINE
	for(unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << " " << std::flush;
	std::cout << std::endl;

	strings[0] = "One";
	strings[1] = "Two";
	strings[2] = "Three";
	strings[3] = "Four";
	strings[4] = "Five";

	a = b;
	b[3] = 5;
	a[3] = 10;
	LINE
	if (a[3] != b[3])
		std::cout << "Изменения в a не затронули пременные b" << std::endl;

	b[0] = 1324;
	b[1] = 999;

	Array<int> c(b);
	LINE
	bool proof = true;
	for(unsigned int i = 0; i < b.size(); i++)
	{
		if (b[i] != c[i])
			proof = false;
	}
	if (proof)
		std::cout << "Верно c полная копия b" << std::endl;

	LINE
	try
	{
		for(int i = 0; i < 10; i++)
			std::cout << strings[i] << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << "Убежали за область выделенной памяти" << std::endl;
	}
	LINE
	return (0);
}
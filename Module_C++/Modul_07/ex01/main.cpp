#include "iter.hpp"
#include <string>

void func(char &a){
	a = a + 1;
}

void Xa(std::string &str){
	str = "Пиу-";
}

void plus_one(int &i){
	i++;
}

int main ( void ){
	char arr[10] = "abcdefghd";
	int b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	std::string str[10];


	::iter(arr, 9, func);
	::iter(str, 10, Xa);
	::iter(b, 10, plus_one);

	std::cout << arr << std::endl;

	for(int i = 0; i < 10; i++)
		std::cout << str[i] << std::flush;
	std::cout << "Пиу!!!" << std::endl;

	for(int i = 0; i < 10; i++)
		std::cout << b[i] << " " << std::flush;
	std::cout << std::endl;
	return (0);
}
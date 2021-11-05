#include "Fixed.hpp"


int main ( void )
{
	Fixed A;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed C;
	std::cout << A << std::endl;
	std::cout << ++A << std::endl;
	std::cout << A << std::endl;
	std::cout << A++ << std::endl;
	std::cout << A << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( A, b ) << std::endl;

	std::cout.precision(32);
	Fixed max;
	Fixed min;
	max.setRawBits(INT_MAX);
	min.setRawBits(INT_MIN);
	std::cout << "Диапозон значений чисел с фиксированной точкой (" << Fixed::getFractionBits() << ") MAX_FIX == " 
	<< max << " MIN_FIX ==" << min << std::endl;
	int i = 0;
	A = 0;
	while(A != 1)
	{
		A++;
		i++;
	}
	std::cout << "Самая минимальная дробь: 1 / " << i << std::endl;
	A.setRawBits(1);
	std::cout << "Её десятичное представление: " << A << std::endl;
	std::cout << "И её двоичное представление: ";
	A.printBinary();

	A = 1;
	C = 2;
	std::cout << "Дано: A == " <<  A << ", C == " << C << std::endl;
	std::cout << "А что больше A или C?" << std::endl;
	if (C > A)
	{
		std::cout << "Верно, C больше чем A, сделаем чтобы C стало равно A?" << std::endl;
		while(C != A)
		{
			C--;
		}
	}
	if (C == A)
		std::cout << "Ура C теперь равно A, C == " << C << std::endl;
	std::cout << "А C + A не меньше 2?" << std::endl;
	if ((C + A) >= 2)
		std::cout << "Да не меньше, потому-что A + C == " << A + C << std::endl;
	std::cout << "А если C разделить на 2, то C не больше 0.5?" << std::endl;
	if ((C / 2) <= 0.5)
		std::cout << "Уффф это было на грани, потому-что C / 2 == " << C / 2 << std::endl;
	std::cout << "А что будет есл мы 1 разделим на 3, а потом результат умножим на 3, станет ли он снова равен 1?\n"
	<< "Результат поместим в С." << std::endl;
	A = 3;
	C = C / A;
	std::cout << "Начнем, (C = (1 / 3)) == " << C << std::endl;
	C = C * A;
	std::cout << "Продолжим С * 3 == " << C << std::endl;
	std::cout << "Вывод: чудес не бывает, компьютер не умеет сохранять бесконечные переодические дроби" << std::endl;
	std::cout << "Так, что будь аккуратней когда будешь сравнивать дроби, попробуем сравнить теперь C c 1?" << std::endl;
	if (C < 1)
		std::cout << "Вот так можно оказаться в той ветке на которую не расчитываешь" << std::endl;
	std::cout << "Посмотрим чему равно А, А == " << A <<" А если отнять? A - 1 == " << A - 1 << std::endl;
	std::cout << "Инкрементариум!!!!!!" << std::endl;

	std::cout << A << std::endl;
	std::cout << ++A << std::endl;
	std::cout << A << std::endl;
	std::cout << A++ << std::endl;
	std::cout << A << std::endl;
	std::cout << --A << std::endl;
	std::cout << A << std::endl;
	std::cout << A-- << std::endl;
	std::cout << A << std::endl;

	std::cout << "Вызавем функции max и min:" << std::endl;
	std::cout << "max == " << Fixed::max(A, C) << std::endl;
	std::cout << "min == " << Fixed::min(A, C) << std::endl;
	std::cout << "P.S Дорогой пир! Можешь попробовать свои примеры! Хорошего настроения!" << std::endl;
	return (0);
}
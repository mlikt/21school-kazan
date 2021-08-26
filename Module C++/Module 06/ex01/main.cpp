#include <iostream>

typedef struct
{
	int x;
	int y;
	int z;
} Data;

uintptr_t serealize( Data * ptr ) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data * deserealize( uintptr_t raw ) {
	return (reinterpret_cast<Data *>(raw));
}

int main ( void )
{
	Data * ex = new Data();
	Data * dub;
	uintptr_t raw;

	raw = serealize(ex);
	dub = deserealize(raw);

	if (ex == dub)
		std::cout << ex << std::endl;

	delete ex;
	return (0);
}

#include "header.hpp"

int main ( int argc, char **argv )
{

	std::string argument;
	int		index;
	void  (* const print_literals[5])(char *arg) = 
	{
		&char_literal, 
		&int_literal, 
		&float_literal, 
		&double_literal,
		&string_literal
	};

	if (argc != 2)
	{
		std::cerr << "Pleas, input one argument" << std::endl;
		return (1);
	}

	index = get_index_func(argv[1]);
	print_literals[index](argv[1]);

	return (0);
}

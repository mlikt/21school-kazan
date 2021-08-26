#include "header.hpp"

void	char_literal (char *arg) {
	char	c;
	int		i;
	float	f;
	double	d;

	c = arg[0];
	i = static_cast<int>	(c);
	f = static_cast<float>	(c);
	d = static_cast<double>	(c);
	print_char(c, f);
	print_int(i, f);
	print_double_and_float(f, d);
}

void	int_literal (char *arg) {
	char	c;
	int		i;
	float	f;
	double	d;

	i = std::atoi(arg);
	f = static_cast<float>	(i);
	c = static_cast<char>	(i);
	d = static_cast<double>	(i);
	print_char(c, f);
	print_int(i, f);
	print_double_and_float(f, d);
}

void	float_literal (char *arg) {
	char	c;
	int		i;
	float	f;
	double	d;

	f = static_cast<float>(std::atof(arg));
	i = static_cast<int>	(f);
	c = static_cast<char>	(f);
	d = static_cast<double>	(f);
	print_char(c, f);
	print_int(i, f);
	print_double_and_float(f, d);
}

void	double_literal (char *arg) {
	char	c;
	int		i;
	float	f;
	double	d;

	d = std::atof(arg);
	i = static_cast<int>	(d);
	c = static_cast<char>	(d);
	f = static_cast<float>	(d);
	print_char(c, f);
	print_int(i, f);
	print_double_and_float(f, d);
}

void	string_literal (char *arg) {
	std::cout << "This literal \"" << arg << "\" is string" << std::endl;
};

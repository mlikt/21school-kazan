#ifndef __HEADER_H__
#define __HEADER_H__

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

#define CHAR	0
#define INT		1
#define FLOAT	2
#define DOUBLE	3
#define STRING	4

void	print_char	(char &c, float &f);
void	print_int	(int &i, float &f);
void	print_double_and_float (float &f, double &d);

void	char_literal	(char *arg);
void	int_literal		(char *arg);
void	float_literal	(char *arg);
void	double_literal	(char *arg);
void	string_literal	(char *arg);

size_t	get_index_char (std::string const &argument);
bool	find_nan_or_inf (std::string const &argument);
void	get_info (bool &point, bool &digit, size_t &i, std::string const &argument);
int		get_index_func (std::string const &argument);

#endif
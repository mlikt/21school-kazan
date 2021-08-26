
#include "header.hpp"

size_t	get_index_char (std::string const &argument) {
	if (argument[0] == '+' || argument[0] == '-')
		return (1);
	return (0);
}

bool	find_nan_or_inf (std::string const &argument) {
	if((!argument.find("nan") && argument.length() == 3 )
		|| (!argument.find("inf") && argument.length() == 3))
		return (true);
	return (false);
}

void	get_info (bool &point, bool &digit, size_t &i, std::string const &argument) {
	while(i < argument.length())
	{
		if (!std::isdigit(argument[i]))
		{
			if (!point && argument[i] == '.')
			{
				point = true;
				i++;
				continue;
			}
			break ;
		}
		digit = true;
		i++;
	}
}

int		get_index_func (std::string const &argument) {
	size_t	i = get_index_char(argument);
	bool	point = false;
	bool	digit = false;
	int		out = CHAR;

	if (find_nan_or_inf(argument))
		return (DOUBLE);
	get_info(point, digit, i, argument);

	if (digit) {
		out = std::atoi(argument.c_str());
		if((out == -1 && argument.length() > 2)
			|| (out == 1 && argument.length() > 1) 
			|| (point && i >= 2))
			out = DOUBLE;
		else
			out = INT;
	}

	if (i != argument.length()) {
		if ((argument.length() > 1 && !point) 
			|| (argument[i] != 'f' && argument.length() > 1)
			|| (argument[i] == 'f' && argument.length() - 1 != i)
			|| (!digit && argument.length() > 1))
			return (STRING);
		if (point && argument[i] == 'f')
			return (FLOAT);
	}

	return (out);
};

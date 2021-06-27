#include "../header/valid_map.h"

char	this_NSWE(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (c);
	return (0);
}

int	this_wall_empty_sprite(char c)
{
	if (c == '1' || c == '2' || c == '0' || c == ' ')
		return (1);
	return (0);
}

int	this_replace(char c)
{
	if (this_NSWE(c) || c == '0' || c == '2')
		return (1);
	return (0);
}

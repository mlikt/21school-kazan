#include <iostream>
#include <fstream>
#include <string>

 int	init_string(std::string const &out_str, std::string &write)
 {
	std::cout << out_str << std::flush;
	std::getline(std::cin, write);
	if (std::cin.eof())
		return (0);
	return (1);
}

int main ( void )
{
	std::string	buf;
	std::string	s1;
	std::string	s2;
	std::string	file;
	size_t		pos;
	int			flag;

	flag = init_string("File name     : ", file);
	if (flag)
		flag = init_string("Find string   : ", s1);
	if (flag)
		flag = init_string("Replace string: ", s2);
	std::ifstream in_file(file);
	if (flag && in_file.is_open())
	{
		if (in_file.peek() == EOF)
		{
			std::cout << "This file empty." << std::endl;
			return (0);
		}
		std::ofstream out_file(file + ".replace");
		while(!in_file.eof())
		{
			if(std::getline(in_file, buf))
			{
				pos = buf.find(s1, 0);
				while(pos != std::string::npos)
				{
					buf.erase(pos, s2.length());
					buf.insert(pos, s2);
					pos = buf.find(s1, pos + s2.length());
				}
				out_file << buf << std::endl;
			}
			else
			{
				out_file << "\n" << std::flush;
			}
		}
	}
	else if (flag)
		std::cout << "bad name file: " << file;
	return (0);
}
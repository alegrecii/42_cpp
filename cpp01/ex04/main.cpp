#include <iostream>
#include <fstream>
int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong args" << std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::ifstream	ifs(filename);
	if (!ifs)
	{
		std::cout << "Can't open input file" << std::endl;
		return (1);
	}
	std::ofstream	ofs(filename + ".replace");
	std::string		line;
	while (std::getline(ifs, line))
	{
		int	start = 0;
		while (line.find(s1,start) != -1)
		{
			int found = line.find(s1,start);
			ofs << line.substr(start, found - start);
			ofs << s2;
			start = found + s1.length();
		}
		ofs << line.substr(start) << std::endl;
	}
	ifs.close();
	ofs.close();
}

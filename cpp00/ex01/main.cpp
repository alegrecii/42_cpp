#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main()
{
	PhoneBook	book;
	std::string	cmd;

	while (1)
	{
		std::cout<<"Insert command:";
		std::getline(std::cin, cmd);
		if (cmd.compare("ADD")== 0 || cmd.compare("add") == 0)
			book.add_contact();
		else if (cmd.compare("EXIT") == 0 || cmd.compare("exit") == 0)
			break;
		else if (cmd.compare("SEARCH")== 0 || cmd.compare("search") == 0)
				book.search_contact();
		else
			std::cout<< "Command not found"<< std::endl;
	}
	return (0);
}

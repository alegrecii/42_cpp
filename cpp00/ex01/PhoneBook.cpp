#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	n = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

bool	check_numeric(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
		if (!isdigit(s[i]))
			return (false);
	return (true);
}

int		PhoneBook::extract_index()
{
	int index = n;
	std::string s;
	while (index >= n || index < 0)
	{
		std::cout << "insert index: ";
		std::getline(std::cin, s);
		if (check_numeric(s))
		{
			index = std::stoi(s);
			index--;
		}
		if (index >= n || index < 0)
			std::cout<<"Please insert a valid index!"<< std::endl;
	}
	return (index);
}

void	PhoneBook::search_contact()
{
	if (n == 0)
	{
		std::cout << "THE PHONEBOOK IS EMPTY!" << std::endl;
		return ;
	}
	std::cout << "|";
	std::cout << std::setw(10)<< "INDEX" <<"|";
	std::cout << std::setw(10)<<"FIRST NAME" <<"|";
	std::cout << std::setw(10)<< "LAST NAME" <<"|";
	std::cout << std::setw(10)<< "NICKNAME" <<"|" << std::endl;
	for (int i = 0; i < n; i++)
		array[i].display_tab(i);
	array[extract_index()].display_info();
	std::cout << std::flush;

}

void	PhoneBook::remove_first(Contact c)
{
	Contact tmp[8];
	tmp[7] = c;
	for (int i = 0; i < 7; i++)
		tmp[i] = array[i + 1];
	for (int j = 0; j < 8; j++)
		array[j] = tmp[j];
}

void	PhoneBook::add_contact()
{
	Contact c;

	c.set_all();
	if (n < 8)
	{
		array[n] = c;
		n++;
	}
	else
		remove_first(c);
}

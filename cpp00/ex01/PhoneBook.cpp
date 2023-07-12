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

void	PhoneBook::search_contact()
{
	int	index;

	std::cout << "|";
	std::cout << std::setw(10)<< "INDEX" <<"|";
	std::cout << std::setw(10)<<"FIRST NAME" <<"|";
	std::cout << std::setw(10)<< "LAST NAME" <<"|";
	std::cout << std::setw(10)<< "NICKNAME" <<"|" << std::endl;
	for (int i = 0; i < n; i++)
		array[i].display_tab(i);
	std::cout << "insert index";
	std::cin >> index ;
	array[index].display_info();
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

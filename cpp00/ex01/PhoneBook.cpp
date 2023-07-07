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

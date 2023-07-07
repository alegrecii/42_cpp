#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main()
{
	Contact ale;
	Contact oo;

	ale.set_all();
	oo.set_all();
	ale.display_tab(1);
	ale.display_tab(2);
	ale.display_tab(3);
	ale.display_tab(4);
	oo.display_tab(5);
	oo.display_tab(6);
	oo.display_tab(7);
	oo.display_tab(8);
	return (0);
}

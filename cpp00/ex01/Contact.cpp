#include "Contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void	Contact::set_first_name()
{
	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
}

void	Contact::set_last_name()
{
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
}

void	Contact::set_nickname()
{
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
}

void	Contact::set_number()
{
	std::cout << "Enter number: ";
	std::getline(std::cin, number);
}

void	Contact::set_secret()
{
	std::cout << "Enter secret: ";
	std::getline(std::cin, secret);
}

void	Contact::set_all()
{

	set_first_name();
	set_last_name();
	set_nickname();
	set_number();
	set_secret();
}

std::string	check_trunc(std::string s)
{
	if (s.length() > 10)
	{
		s = s.substr(0, 10);
		s[9] = '.';
	}
	return (s);
}

void	Contact::display_info()
{
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Number: " << number << std::endl;
	std::cout << "Darkest Secret : " << secret << std::endl;
}

void	Contact::display_tab(int index)
{
	std::cout << "|";
	std::cout << std::setw(10)<< index <<"|";
	std::cout << std::setw(10)<< check_trunc(first_name) <<"|";
	std::cout << std::setw(10)<< check_trunc(last_name) <<"|";
	std::cout << std::setw(10)<< check_trunc(nickname) <<"|" << std::endl;
}

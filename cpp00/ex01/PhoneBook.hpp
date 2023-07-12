#ifndef PHONEBOOK_CLASS_H
	#define PHONEBOOK_CLASS_H
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact array[8];
	void	remove_first(Contact c);
	int	n;
public:
	PhoneBook();
	~PhoneBook();
	void	add_contact();
	void	search_contact();

};

#endif

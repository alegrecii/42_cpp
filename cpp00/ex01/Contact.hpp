#ifndef CONTACT_CLASS_H
	#define CONTACT_CLASS_H
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string number;
	std::string secret;
	void	set_first_name();
	void	set_last_name();
	void	set_nickname();
	void	set_number();
	void	set_secret();

public:
	Contact(void);
	~Contact(void);
	void	set_all();
	void	display_info();
	void	display_tab(int index);
};
#endif

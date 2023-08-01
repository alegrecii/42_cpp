#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl is alive!" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl is dead!" << std::endl;
}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*funcs[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	compare[4] = {"debug", "info", "warning", "error"};
	int	s_level = 8;
	for (int i = 0; i < 4; i++)
		if (level == compare[i])
			s_level = i;
	switch(s_level)
	{
		case 0 :
			(this->*funcs[s_level++])();
		case 1 :
			(this->*funcs[s_level++])();
		case 2 :
			(this->*funcs[s_level++])();
		case 3 :
		{
			(this->*funcs[s_level])();
			break;
		}
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}



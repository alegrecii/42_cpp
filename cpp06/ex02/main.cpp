#include"Base.hpp"

Base *generate(void)
{
	int i = std::rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void	identify(Base *p)
{
	std::cout << "Pointer is pointing to: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Something wrong" << std::endl;
}

void identify(Base &p)
{
	std::cout << "Reference is pointing to: ";
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Something wrong" << std::endl;
			}
		}
	}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	Base *p = generate();
	identify(p);
	identify(*p);
	delete p;
	return 0;
}

